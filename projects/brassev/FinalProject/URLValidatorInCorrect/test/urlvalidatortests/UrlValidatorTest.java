package urlvalidatortests;

import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import junit.framework.TestCase;
import urlvalidator.UrlValidator;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!



public class UrlValidatorTest extends TestCase {

	
	/* Private members */
	private Pattern REGEX; /* Regex for oracle */
	private String[] testSchemes;
	private String[] testAuthorities;
	private String[] testPorts;
	private String[] testPaths;
	private String[] testQueries;
	

	/* Public methods */
	/* Constructor */
	public UrlValidatorTest(String[] testSchemes, String[] testAuthorities,
			String[] testPorts, String[] testPaths, String[] testQueries, String testName) {
		
		/* Set private members */
		super(testName);
		this.testSchemes = testSchemes;
		this.testAuthorities = testAuthorities;
		this.testPorts = testPorts;
		this.testPaths = testPaths;
		this.testQueries = testQueries;
		
		/* Diego Perini's super powerful URL validation regex */
		/* https://gist.github.com/dperini/729294 */
		this.REGEX = Pattern.compile("(?i)^(?:(?:https?|ftp)://)(?:\\S+(?::\\S*)?@)?(?:(?!(?:10|127)(?:\\.\\d{1,3}){3})(?!(?:169\\.254|192\\.168)(?:\\.\\d{1,3}){2})(?!172\\.(?:1[6-9]|2\\d|3[0-1])(?:\\.\\d{1,3}){2})(?:[1-9]\\d?|1\\d\\d|2[01]\\d|22[0-3])(?:\\.(?:1?\\d{1,2}|2[0-4]\\d|25[0-5])){2}(?:\\.(?:[1-9]\\d?|1\\d\\d|2[0-4]\\d|25[0-4]))|(?:(?:[a-z\\u00a1-\\uffff0-9]-*)*[a-z\\u00a1-\\uffff0-9]+)(?:\\.(?:[a-z\\u00a1-\\uffff0-9]-*)*[a-z\\u00a1-\\uffff0-9]+)*(?:\\.(?:[a-z\\u00a1-\\uffff]{2,}))\\.?)(?::\\d{2,5})?(?:[/?#]\\S*)?$");
	}

	/* Should return true if URL is valid, false otherwise */
	public boolean regexURLOracle(String url) {
		Matcher matcher = this.REGEX.matcher(url);
		return matcher.find();
	}
	
	/* Combine all the test URLs bits in this UrlValidatorTest object */
	public ArrayList<String> combineURLParts() {
		ArrayList<String> URLs = new ArrayList<String>();
		for (String scheme : this.testSchemes) {
			for (String authority : this.testAuthorities) {
				for (String port : this.testPorts) {
					for (String path : this.testPaths) {
						for (String query : this.testQueries) {
							String url = scheme + authority + port + path + query;
							URLs.add(url);
						}
					}
				}
			}
		}
		return URLs;
	}

	// Main method
	public static void main(String[] argv) {
		
		/* Part A test strings */
		String[] testSchemes = {"http://", "ftp://", "h3t://", "3ht://", "http:/",
                               "http:", "http/", "://", ""};

		String[] testAuthorities = {"www.google.com",
								   "go.com",
								   "go.au",
								   "0.0.0.0",
								   "255.255.255.255",
								   "256.256.256.256", 
								   "255.com",
								   "1.2.3.4.5", 
								   "1.2.3.4.", 
								   "1.2.3", 
								   ".1.2.3.4", 
								   "go.a", 
								   "go.a1a", 
								   "go.1aa", 
								   "aaa.", 
								   ".aaa", 
								   "aaa", 
								   ""};

	   String[] testPorts = {":80",
							 ":65535",
							 ":0",
							 "",
							 ":-1",
							 ":65636",
							 ":65a"};

	   String[] testPaths = {"/test1",
							 "/t123", 
							 "/$23",
							 "/..",
							 "/../", "/test1/", 
							 "", 
							 "/test1/file", 
							 "/..//file", 
							 "/test1//file"};


	   String[] testQueries = {"?action=view",
							   "?action=edit&mode=up",
							   ""};



	   /* UrlValidatorTest mostly serves to combine strings */
	   /* I should probably refactor the test loop below to its own function */
	   UrlValidatorTest test = new UrlValidatorTest(testSchemes, testAuthorities,
				testPorts, testPaths, testQueries, "URL testing");

	   /* Initialize a UrlValidator so we have access to .isValid() */
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   ArrayList<String> URLs = test.combineURLParts();
		
	   /* Ready output for test loop */
	   try {
		   System.setOut(new PrintStream(new FileOutputStream("test.out")));
	   } catch (FileNotFoundException e1) {
		   // TODO Auto-generated catch block
		   e1.printStackTrace();
	   }

	   /* Variables for test loop */
	   int i = 0;
	   int numPasses = 0;
	   int numFails = 0;
	   int numExceptions = 0;
	   boolean isValid;
	   boolean oracle;

	   System.out.println("Unit testing");
	   for (String url : URLs) {
			i++;
			/* Try / catch when testing URLs */
			try {
				isValid = urlVal.isValid(url);
				oracle = test.regexURLOracle(url);
				System.out.print("Test " + i + " >> check " + url + " - ");
				if (isValid == oracle) {
					System.out.println("PASS");
					numPasses++;
				} else {
					System.out.println("FAIL - isValid:" + isValid + ", oracle: " + oracle);
					numFails++;
				}
			}
			catch (Exception e) {
				/* Generic exception handler - just see what happened */
				System.out.print("Test " + i + " >> check " + url + " - ");
				System.out.println("EXCEPTION thrown at " + e.getStackTrace()[0]);
				numExceptions++;
			}
		}

		/* Print summary of results */
		System.out.println("Number of passed test cases: " + numPasses);
		System.out.println("Number of failed test cases: " + numFails);
		System.out.println("Number of test cases with exceptions thrown: " + numExceptions);
		
	}

}