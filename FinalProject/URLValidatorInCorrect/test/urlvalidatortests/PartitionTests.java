package urlvalidatortests;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

import urlvalidator.UrlValidator;

class PartitionTests {
	private UrlValidator val;
	
	PartitionTests() {
		String[] validSchemes = {"ftp", "http"};
		this.val = new UrlValidator(validSchemes, 0);
	}
	
	// Schemes:
	@Test
	void validSchemes() {
		assertEquals(true, this.val.isValid("ftp://google.com"), "ftp is a valid scheme");
		assertEquals(true, this.val.isValid("http://google.com"), "http is a valid scheme");
		
	}
	@Test
	void invalidSchemes() {
		assertEquals(false, this.val.isValid("bogus://google.com"), "bogus is a not valid scheme");
		assertEquals(false, this.val.isValid("fail://google.com"), "fail is a not valid scheme");
	}
	
	// Hosts:
	@Test
	void validHost() {
		assertEquals(true, this.val.isValid("http://google.com"), "google is a valid host");
		assertEquals(true, this.val.isValid("ftp://bank.com"), "bank is a valid host");
		
	}
	@Test
	void hostWithPort() {
		assertEquals(true, this.val.isValid("http://bank.com:1"), "1 is a valid port");
		assertEquals(true, this.val.isValid("http://bank.com:01"), "01 is a valid port");
		assertEquals(true, this.val.isValid("http://bank.com:001"), "001 is a valid port");
		assertEquals(true, this.val.isValid("http://bank.com:000080"), "000080 is a valid port");
	}
	@Test
	void invalidPort() {
		assertEquals(false, this.val.isValid("http://google.com:11111111111"), "11111111111 is a not valid port");
	}
	@Test
	void hostIP() {
		assertEquals(true, this.val.isValid("http://192.168.1.1"), "192.168.1.1 is a valid ip");
		assertEquals(true, this.val.isValid("http://1.0.0.1"), "1.0.0.1 is a valid ip");
	}
	@Test
	void unicodeHost() {
		assertEquals(true, this.val.isValid("http://\u02e5.com"), "\u02e5.com is a valid host");
	}
	@Test
	void unicodeInvalid() {
		assertEquals(false, this.val.isValid("http://\u02e5 .com"), "http://\u02e5 .com is not a valid host");
	}
	@Test
	void invalidIP() {
		assertEquals(false, this.val.isValid("http://1.0.0.1.1"), "1.0.0.1.1 is not a valid ip");
	}
	@Test
	void invalidHost() {
		assertEquals(false, this.val.isValid("bogus://goo gle.com"), "goo gle is a not valid host");
		
	}
	// - Host length
	@Test
	void smallestHost() {
		assertEquals(true, this.val.isValid("http://a.com"), "a is a valid host");
	}
	@Test
	void largeHost() {
		assertEquals(true, this.val.isValid("http://aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.com"), "a..a is a valid host");
	}
	
	// Paths:
	@Test
	void validPaths() {
		assertEquals(true, this.val.isValid("http://google.com/"), "Failed a valid path");
		assertEquals(true, this.val.isValid("http://google.com/a/"), "Failed a valid path");
		assertEquals(true, this.val.isValid("http://google.com/a/a/"), "Failed a valid path");
	}
	@Test
	void invalidPaths() {
		assertEquals(false, this.val.isValid("http://google.com/a/../a"), "No backwards paths");
		
	}
	// - Path length:
	@Test
	void shortPath() {
		assertEquals(true, this.val.isValid("http://google.com/a"), "Failed a valid path");
	}
	@Test
	void longPath() {
		assertEquals(true, this.val.isValid("http://google.com/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/"), "Failed valid path");
	}
	
	
	
}
