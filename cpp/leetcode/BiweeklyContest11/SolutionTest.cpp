#include "Solution.h"
#include <gtest/gtest.h>

TEST(BiweeklyContest11, test) {
//    ASSERT_EQ(9, missingNumber({5,7,11,13}));
//    ASSERT_EQ(14, missingNumber({15,13,12}));
//    std::vector<int> res{60,68};
//    ASSERT_EQ(res, minAvailableDuration({{10,50},{60,120},{140,210}}, {{0,15},{60,70}}, 8));
//    ASSERT_TRUE(minAvailableDuration({{10,50},{60,120},{140,210}}, {{0,15},{60,70}}, 12).empty());
//    std::vector<int> res{98730764,99186849};
//    std::vector<std::vector<int>> slots1{{216397070,363167701},{98730764,158208909},{441003187,466254040},{558239978,678368334},{683942980,717766451}};
//    std::vector<std::vector<int>> slots2{{50490609,222653186},{512711631,670791418},{730229023,802410205},{812553104,891266775},{230032010,399152578}};
//    ASSERT_EQ(res, minAvailableDuration(slots1, slots2, 456085));
//    ASSERT_DOUBLE_EQ(0.4, probabilityOfHeads({0.4}, 1));
//    ASSERT_DOUBLE_EQ(0.03125, probabilityOfHeads({0.5,0.5,0.5,0.5,0.5}, 0));
//    ASSERT_DOUBLE_EQ(0.182, probabilityOfHeads({0.2,0.8,0,0.3,0.5}, 3));
//    ASSERT_EQ("10", encode(5));
//    ASSERT_EQ("000", encode(7));
//    ASSERT_EQ("001", encode(8));
//    ASSERT_EQ("010", encode(9));
//    ASSERT_EQ("100", encode(10));
//    ASSERT_EQ("011", encode(11));
//    ASSERT_EQ("110", encode(12));
//    ASSERT_EQ("011", encode(13));
//    ASSERT_EQ("110", encode(14));
//    ASSERT_EQ("111", encode(15));
//    ASSERT_EQ("1000", encode(23));
//    ASSERT_EQ("101100", encode(107));
//    vector<vector<string>> regions{{"zDkA","GfAj","lt"},{"GfAj","rtupD","og","l"},{"rtupD","IT","jGcew","ZwFqF"},{"og","yVobt","EjA","piUyQ"},{"IT","XFlc","W","rB"},{"l","GwQg","shco","Dub","KwgZq"},{"jGcew","KH","lbW"},{"KH","BZ","sauG"},{"yVobt","Aa","lJRmv"},{"BZ","v","zh","oGg","WP"},{"XFlc","Sn","ftXOZ"},{"sauG","If","nK","HHOr","yEH","YWMgF"},{"GwQg","Mfb","gr","S","nQ"},{"shco","xsUkW"},{"xsUkW","Cssa","TgPi","qx"},{"v","SAH","Rjr"},{"lt","Q","fWB","a","Wk","zpqU"},{"If","e","y","quEA","sNyV"},{"piUyQ","G","aTi"},{"Sn","rVIh","twv","pYA","Ywm"},{"zh","PWeEf"},{"Mfb","GEs","XjpeC","p"},{"GEs","oXMG","tNJYJ"},{"SAH","bmFhM"},{"bmFhM","SOvB","RWsEM","z"},{"SOvB","iD","pLGYN","Zqk"},{"Dub","PnGPY"},{"a","TekG","zp"},{"XjpeC","vK","aaO","D"},{"pLGYN","ldb"},{"oGg","x"},{"nQ","IOw"},{"Aa","wmYF"},{"Zqk","th"},{"ZwFqF","GDl"},{"th","JyOSt","ALlyw"},{"lbW","M"},{"yEH","UY","GIwLp"},{"JyOSt","i"},{"x","dclJ"},{"wmYF","xreBK"},{"PnGPY","Ev","lI"},{"ALlyw","jguyA","Mi"},{"oXMG","uqe"},{"sNyV","WbrP"}};
//    ASSERT_EQ("GfAj", findSmallestRegion(regions, "RWsEM", "GfAj"));
    vector<vector<string>> synonyms{{"happy","joy"},{"sad","sorrow"},{"joy","cheerful"}};
    generateSentences(synonyms, "I am happy today but was sad yesterday");
}
