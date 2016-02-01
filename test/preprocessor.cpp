#define BOOST_TEST_MODULE TEST_preprocessor
#include <boost/test/included/unit_test.hpp>

#include <DefaultPreprocessor.h>

BOOST_AUTO_TEST_CASE(preprocessor_semicolon_comment) 
{
	std::string src = 
		"abc\n"
		"def;hij\n"
		";klm\n"
		"nop;\n"
		"qrs;tuv;wxy\n"
		"z";
	
	DefaultPreprocessor pre(src.begin(), src.end());
	pre.removeSemicolonComments();
	std::string actual = pre.getWorkingData();
	std::string expected = 
		"abc\n"
		"def\n"
		"\n"
		"nop\n"
		"qrs\n"
		"z";
	
	BOOST_TEST(actual == expected);
}

BOOST_AUTO_TEST_CASE(preprocessor_slashstar_comment)
{
	std::string src = 
		"a*/b/*c\n"
		"defhij\n"
		"k*/lm\n"
		"nop\n"
		"qrs/*tuvwxy\n"
		"z";
	
	DefaultPreprocessor pre(src.begin(), src.end());
	pre.removeSlashStarComments();
	std::string actual = pre.getWorkingData();
	std::string expected = 
		"a*/blm\n"
		"nop\n"
		"qrs";
	
	BOOST_TEST(actual == expected);
}

BOOST_AUTO_TEST_CASE(preprocessor_combined)
{
	std::string src = 
		"a*/b/*c\n"
		"def;hij\n"
		"k*/lm\n"
		"no;p\n"
		"qr;s/*tuvwxy\n"
		"z";
	
	DefaultPreprocessor pre(src.begin(), src.end());
	std::string actual = pre();
	std::string expected = 
		"a*/blm\n"
		"no\n"
		"qr\n"
		"z";
	
	BOOST_TEST(actual == expected);

}
