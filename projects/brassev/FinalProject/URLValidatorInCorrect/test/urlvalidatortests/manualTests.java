package urlvalidatortests;
import urlvalidator.UrlValidator;

//import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class ManualTests {

	@Test
	void Manual() {
		String[] schemes = {"http","https"};
	    UrlValidator urlVal = new UrlValidator(schemes);//UrlValidator.ALLOW_ALL_SCHEMES);
	    boolean testurl;
	    
	    //valid
	    testurl = urlVal.isValid("http://www.google.com/testPath?testQuery#testFragment");
	    System.out.println(testurl);
	    
	    //invalid scheme
	    testurl = urlVal.isValid("htt://www.google.com/testPath?testQuery#testFragment");
	    System.out.println(testurl);
	    //invalid host
	    urlVal.isValid("http:///testPath?testQuery#testFragment");
	    System.out.println(testurl);
	    //invalid path
	    urlVal.isValid("http://www.google.com//testPath?testQuery#testFragment");
	    System.out.println(testurl);
	    //invalid query
	    urlVal.isValid("http://www.google.com/testPath*testQuery#testFragment");
	    System.out.println(testurl);
	    //invalid fragment
	    urlVal.isValid("http://www.google.com/testPath?testQuerytestFragment");
	    System.out.println(testurl);
	}
}
