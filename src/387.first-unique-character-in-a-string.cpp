/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (55.60%)
 * Likes:    3963
 * Dislikes: 171
 * Total Accepted:    889.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '"leetcode"'
 *
 * Given a string s, find the first non-repeating character in it and return
 * its index. If it does not exist, return -1.
 *
 *
 * Example 1:
 * Input: s = "leetcode"
 * Output: 0
 * Example 2:
 * Input: s = "loveleetcode"
 * Output: 2
 * Example 3:
 * Input: s = "aabb"
 * Output: -1
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only lowercase English letters.
 *
 *
 */

#include "common/common.hpp"

// @lc code=start
class Solution {
 public:
  int firstUniqChar(string s) {
    std::array<size_t, 'z' - 'a' + 1> count{};
    for (auto c : s) {
      count[c - 'a']++;
    }

    for (size_t i = 0; i < s.size(); ++i) {
      if (count[s[i] - 'a'] == 1) {
        return static_cast<int>(i);
      }
    }

    return -1;
  }
};
// @lc code=end

TEST_CASE("387.first-unique-character-in-a-string") {
  Solution s;
  CHECK(s.firstUniqChar("leetcode") == 0);
  CHECK(s.firstUniqChar("loveleetcode") == 2);
  CHECK(s.firstUniqChar("aabb") == -1);
  CHECK(
      s.firstUniqChar(
          "uindrseqbljlhqvlwvgdebeihttirikuahlikgnahvgnptmqwbovmuwesxkvcitcwrwr"
          "ucsbbfqvldridfviduqvmfcmeiphoqupbitnwdbvevouoaetisdmgvvvwoglwtgjrpcb"
          "ghxkrkjthetxeexbphbjiehaicuicgnirslhdstgmqcdnlulpdpadjdltfouwhfqicfc"
          "qntnpeqaohslwkhbvflxaudembsrsindluthxapnmrqinsivbxmkohubvmmmpmklbfrm"
          "euvdrhptdmelmjjefgbsqqlbqhvsmswwxrlkutadqbbeisbgfrcivvoxmxxptrscxnjj"
          "vtajfhqiucdihihcutxhlonlomfdnbwanrcnbarojsajseqrgkuqgkcnvrghxnmbclfo"
          "mktwfaakodeecsglufvobkgoqsbrhdiuhxqbcndkmxuertupngvnkgwrfwgdbiurboox"
          "ariklwarjgavsuddoveipltessrssxwxgvrrtkisnbavkbpaphicxhapjjpkccakepua"
          "fjdaswfwfmbdmuuaveukxvnpkgmhcjcpqntssthjlvrngugbhrivtwmbrvrprrlfmvwj"
          "dkonfmgnepqoxwfcvefjihisarwskjfmqrjlkbbugfawmkqgfxgpokkxxivqbqimwscc"
          "dekjegwcxhmmuhpstxfpofwmrmhrxeptxwbvxsesheijjfsshgrrwckjkmbslpbngnwh"
          "okjnujtiepfrdhiwwgbffixaidabacaibummwxgxowsewlqfxrkarjrkqxmxwobqbcoo"
          "wmbggtpoqadhqdxlhvxrkfuwpxxgnchudreoeuefkqhlrmwwfvjexvbxdhtdngwvoohp"
          "jtdbdbesceiafrhenfljleegsencfmbauxlltfueudnjxsiiggsfwiuidgktsbtcvxtd"
          "llviocfdbonjciosucbjidwxnogmnveqkcrxbpamfxwxiugjgrfpstromuxxdiodqeoq"
          "dlfulttraquskhwfholbrcbchijlgqvuwxvejedikvgetlmrcmeampdgjvmbdovkcjil"
          "bralhmniwvbeandldnudkpjvhoqtfdwllridwljfvflfdrbqadvabggwsiexrthrngex"
          "pebuhtefkqgkkjoopsmunesfotsprxuaswwenhkdvsspkppulecahkkvccqngeaoijjg"
          "vsfqfpvphvhdnkkcqsebhijkvfpqjmarbkpejagtbtisnflrrvawmvfxeccxtrmorihg"
          "slxlqrqcmouojjfhcieuwlrcqhevmveookgonxqdbtgqjimsidnaaiuchwkfkpxfptuv"
          "hfqemojixqvhgokdekdwbomptqqlfiaiptxvgfmovdqxupjxjpoxuplsagxpgpmvtcpa"
          "wkrrthvclhdbpqeucchxptdceswhnqocmeocpgthkgxmxggwlnantwwuoqpmnpvgatei"
          "txlocmhnihmfgjnvrggenbhnjfubtoteojojjkjpcnwqthxhlfukingjletwnxdnjwrg"
          "jopqoxtqcvwsakqxxumbtcblufdmdvxfkshitenmenkxjvblsoiyhjpakinimwxhceba"
          "bgsvqftfvwjnstltjawhwipkubadtoxqrutkwxjnmfoowtnvqplvqokcuwlkmxxhboam"
          "pcdwokjfxggtnojebagxlwaeowtomubtbfsrufkttugfpnxmipkcsphqafjuxovwpcgo"
          "nhiqmomsweunoeqkpkxxsdksmufowqpmkontccckcdbwrfwamikananakgjkahndrepe"
          "mcgxecgpltvdbpoexemnrejdephuuxhfcubxlbdrmhvmeqmtdhnbkwnidigxdantmkck"
          "ijiecavkpumegrbveffclcltmibjcstrrauphfxxssgxkkirapiihnlbrodvfostahqd"
          "kajqtrrfwdsemwxlucbbjjspnnqjnpnpmimhulgoskwpsactexmkfdhaihnlggqeunqe"
          "vxfrpiwskhrhgfluelshqejavomjshfomvgpugqesbtakvxqwrtguuebcgqphocglfri"
          "rcfvuikfbviomfrsnpvvlftwrkbmjpvdpgvohtmxcxwnuhwojnfvsfwvdlaxxlmafihp"
          "ussffcawjpaxdwerwfbvsbipljualcnhseealvqiqfiaiskaafufaubvhjglktfhbdsa"
          "skmedroxkrxshnggumcbtdcablawkodmnafkjekuiecqlvbxocfcwipaicgndfafjhtj"
          "celakrecmntjxeqjqgxkxapuobbcaxfrpsktjswxdfvugmmgjwiphnsclqwmranthpiu"
          "effaxvhplajqsrtoxbixbdpcfkbpkjkelemubwachcpxcniaqmkmasmvlfcubcdkxfku"
          "pgcgbrvmbmgnjgfbawmmdritdrkppswatwtdjemhifhmshunkvaivhteqnwkdcrpfxmr"
          "afupfhbgligbvrqjkvcgbiqudvtblhfgetffduvsfhsmjimgruxrvbqniluapaoniwhq"
          "hltbxvrphmlisfaomqoecmdbbrgujgsbdelkbddcgmpggogfonssxisphbwljlvhwhew"
          "mpqugxgbubqfeilobxxhtcxmxvjtbuavxlaghhjiemihvrsjxbleutpuumgndtnocwkp"
          "kdaupbmcsahcbwoelmgnwqummmekwhpahtdvehoprfcciwqphfwppscruimikiximhbk"
          "domovbdalsihioncpaclevxawqcqthtmuogolkrvlipropmnmecttmlecpapdlrcqxop"
          "fjobgsvhcadqiudqjoscpvjguddnorldkpqtoocrtkcutkvdpbkkekenpqjmxmuxccam"
          "kwwxrdrbdmameptvcgsltqdasicoouvdtbranexokmtkioptqblrruaihvfvvebjigku"
          "wwgearxvmimlgmxgpvbnotepprknjxcunheclsvxxmmoufvdhrwxqlrkmvcaxtbiqrjr"
          "nrsfrkvttnpxbspnetcofhpcbcphrchivnrskkalsvdllhtisnaerxbcxutcpmnquwru"
          "tmmvrtchhheplhdmbfkrrrxalosjbebtdqtsjbdcuuatgldnubigijbkehxsmhsadwtc"
          "bwinlnilthiqslvsduspkjuunpetcofujbqhtkmalnjmllhulckqodbgffxdiqjajecb"
          "mlekvepkirxnguqnpnfjdptinuphcoxkoqhqrmkkawmngqwvfpcuxgpekkprupplsbws"
          "hmsduaitlhcjargacduewtqgnxbtpwrkawpncarxlsnardkftmsdjflmhoplghandjis"
          "upacixxthwokctbxekqwbmhtoutgrogxsdnmcaqrsqrpigbigqhsmrksxgkdbdbxkwim"
          "pehltcffuhrphbaqgvabjduudbrxgwiljkwijvaugnleamskjijhnvcspagsfnhjielr"
          "vxddxqfgaipfflffksmvgaioaclfsjhovcotoaiwhhnmrudsqmsepsgdofnxjjcgdeju"
          "tmdtgauuvuepajlikebtpgfimudswplfwgaodtwqjuaujlbqqartevsqesmrpknoanfp"
          "rqcwochqdrcvquovtsogptduvfiaislfvpxwsqitodxwckprpfxtqhbdixklhtsajqgb"
          "infpdqaehrwhnwggmggnbstolrcbmlhpfjurbknpwbrfhvdanrjcwnvsxudagbkhdlwu"
          "jqvwpbbgmsfrkgutkqwxqfemaaokrfdocsbbktwaugoadgvqcdhmqkworbvxqwdpmbjk"
          "qghmapevrsnaaparwnbvcfnhhgfqplfwiswrxxistamulcbxcmvkbcxsgftbmbvqlxrh"
          "bmcujkktdvcgnjkfaclxndtjkdbgqvbqxicgmpowbjsfvspvxtrovjwbbkaapfgcqbif"
          "dosnmutvfbgdmhiqvflasedhafqnmrlmwbuhmptnkvvojnjngiepmdktewwsuxernpfm"
          "ktsgwwnxfvmuotpfxfntcrsjpldmringfpkpievvbgbghevlmuticukrfvahrmtkvckj"
          "bxxrmkilbeojsxgbvbhsgvkhgtjddoreipbkwiqbkecobfexswiwttlohnfwokixfmfr"
          "padtudrssiobbvhctpbeesiogwhdqojoalxpxikwuheilvsrxbfbnckjeswhkfviihvw"
          "rfxkxcomhvsjojhltospooumkstqqnvxmrowlrtufhxkipxnfecchklrqljfwnglxeha"
          "remawsbvnuentnapewjhnzbieisjtomdqtjkigisgopmgcfqxcxninrisupchhmfrosx"
          "gdtakhrrnbbnxovvbfjgwdgnlxoxswhsfjeijvivqemoekkmrttscthlpglaorarhibr"
          "ucuhikfkphqmhowloobeumlikqmmlatesupiekwjhdvntnjbakohrbobimmujkbatfxp"
          "mgfmmqsgwsffcbenwgdrhlqrsmfghevnjfdlxupihmkptsefubmixhacnxngpjrckxhv"
          "hrelolqwevoqklhxbplakmsxdetvpuddmvaodpglmsknbvfftstckjurbntwqenuhcur"
          "xqvotrxfpootqkobeatoduihwhpjxxrvboggkcxagnrrfwfuaqplirlnafprumnkcjxl"
          "pvanfmqwuoaupqptqeulpwvnhbahbkihustenkbdushjakemufdhjllnowmvgpdxbrhx"
          "fonpgcjslvwgdmajicqqmdxubrofvdodfsedjghpbjncgkckeudxwascljlraoodwvgp"
          "vojcqgbalntslsfrwnfcdvidsdrvwhscskpalubxeobapkgpdsqcjpwkednraijmbcre"
          "plwijofniggavpdlwfmwnvsaridhbppeolakquhamneffnfmbruivassdaaikxiaxupg"
          "dpgkfojvkkagcsmqnweofwikvevrsottkbtcldoruakajinnlgxmpddcrmohaktsdrxj"
          "elrbmfdthspikxeocqqdordrqwjtaxihswcubtfomksaxddcvtadnrtqkmdnacgduudt"
          "dbhsgpfomrdiaotcfwqlxccqeelgtnkflgixpjcriroruhbbgpidwkggdevpfratqebe"
          "waxcudseaikqjuuhpsguvtwxniofskkslfnrphatmxngneuituefcxufisrsjitqxwuf"
          "rgidbwlmkrqojpwpljasaiukwwthrudhcocoguerakhajdncxbrnuavoqeuwsamwdqgu"
          "tbaoixcgeibpoajhedooqcewiqvddedmanxljjjcbojgbmwabkfbvamgnfpncdcxoaqh"
          "mgurifpwpgrpctlqpwmqraknjltneknsphtwbnbiahknxipsovljkivlpggvldeveeop"
          "voqlvfjbratadttlcecomllpkdgiloeedquivsnmxkfcvrkwaohgbrbvjklkktgwtlfg"
          "afqgbigheajrvffvvkkmibcedfmnwasopoqgxjohjoqnijeaifuwiwmogkwqlfmibuwe"
          "cvnulvhkbsukscqlqlsxjulillmlgjkrbmllcunhbqmbujftqgkpwkvemthigednfohx"
          "psduotwfnknfjbexflcfieaosnlhndsorbkcdlahovwbccshmrlcofowrmqajluiqaar"
          "nqtxokbaddswftiexiahmstpbonwmhvqgcpmfrocvtwfhjrtsupscfmvwfvaoolanrlg"
          "dsvgoseltdnoxrdglockhwlvffaakgrxjfnfbxnbprfvpwmexnhfekjnkenbohhmwlqo"
          "teiwgtjsrnceptbgwkfcmtkliwwqskmsoihmnbjsvnmfkwbwemijdtpnajgrousbrdaa"
          "genqlgeaiixfgcbfhceaxkwxbpksfouuqcvcerqecpdtvtsubbadmaatdnmnqhladeia"
          "pejkxffoagbwqbvppssvvvhlvhntatxlvqgjxbejpvxemqbdjknuogumrwbognklmvjs"
          "ldrktpeowiuaapbjgktxwfjiferxgmafbcerteqlvpqvxbgdwiufdctkwptadtujmifp"
          "pudubpmdtiedmqhnihquansnjufpbuumhhmidphkwusjdsdaocavtauhsvtgcoqhufma"
          "cwcbxvjmagkounkoqpcnoanhgwsjvgtlwgvbpdbufekosgagfsmadmvbonkrtcbspoab"
          "ugkcjeebqhqwfjcqlqjvabaqecofgwskqplgup") == 1615);
}