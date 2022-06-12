#include <string>
#include <fstream>
#include <map>
#include <unordered_set>
#include <vector>

auto gnu_list = std::unordered_set<std::string>{
"aa_DJ",
"aa_ER",
"aa_ET",
"af_ZA",
"agr_PE",
"ak_GH",
"am_ET",
"anp_IN",
"an_ES",
"ar_AE",
"ar_BH",
"ar_DZ",
"ar_EG",
"ar_IN",
"ar_IQ",
"ar_JO",
"ar_KW",
"ar_LB",
"ar_LY",
"ar_MA",
"ar_OM",
"ar_QA",
"ar_SA",
"ar_SD",
"ar_SS",
"ar_SY",
"ar_TN",
"ar_YE",
"ast_ES",
"as_IN",
"ayc_PE",
"az_AZ",
"az_IR",
"bem_ZM",
"ber_DZ",
"ber_MA",
"be_BY",
"bg_BG",
"bhb_IN",
"bho_IN",
"bho_NP",
"bi_VU",
"bn_BD",
"bn_IN",
"bo_CN",
"bo_IN",
"brx_IN",
"br_FR",
"bs_BA",
"byn_ER",
"ca_AD",
"ca_ES",
"ca_FR",
"ca_IT",
"ce_RU",
"chr_US",
"ckb_IQ",
"cmn_TW",
"cns11643_stroke",
"crh_UA",
"csb_PL",
"cs_CZ",
"cv_RU",
"cy_GB",
"da_DK",
"de_AT",
"de_BE",
"de_CH",
"de_DE",
"de_IT",
"de_LI",
"de_LU",
"doi_IN",
"dsb_DE",
"dv_MV",
"dz_BT",
"el_CY",
"el_GR",
"en_AG",
"en_AU",
"en_BW",
"en_CA",
"en_DK",
"en_GB",
"en_HK",
"en_IE",
"en_IL",
"en_IN",
"en_NG",
"en_NZ",
"en_PH",
"en_SC",
"en_SG",
"en_US",
"en_ZA",
"en_ZM",
"en_ZW",
"eo",
"es_AR",
"es_BO",
"es_CL",
"es_CO",
"es_CR",
"es_CU",
"es_DO",
"es_EC",
"es_ES",
"es_GT",
"es_HN",
"es_MX",
"es_NI",
"es_PA",
"es_PE",
"es_PR",
"es_PY",
"es_SV",
"es_US",
"es_UY",
"es_VE",
"et_EE",
"eu_ES",
"fa_IR",
"ff_SN",
"fil_PH",
"fi_FI",
"fo_FO",
"fr_BE",
"fr_CA",
"fr_CH",
"fr_FR",
"fr_LU",
"fur_IT",
"fy_DE",
"fy_NL",
"ga_IE",
"gd_GB",
"gez_ER",
"gez_ET",
"gl_ES",
"gu_IN",
"gv_GB",
"hak_TW",
"ha_NG",
"he_IL",
"hif_FJ",
"hi_IN",
"hne_IN",
"hr_HR",
"hsb_DE",
"ht_HT",
"hu_HU",
"hy_AM",
"ia_FR",
"id_ID",
"ig_NG",
"ik_CA",
"is_IS",
"it_CH",
"it_IT",
"iu_CA",
"ja_JP",
"kab_DZ",
"ka_GE",
"kk_KZ",
"kl_GL",
"km_KH",
"kn_IN",
"kok_IN",
"ko_KR",
"ks_IN",
"ku_TR",
"kw_GB",
"ky_KG",
"lb_LU",
"lg_UG",
"lij_IT",
"li_BE",
"li_NL",
"ln_CD",
"lo_LA",
"lt_LT",
"lv_LV",
"lzh_TW",
"mag_IN",
"mai_IN",
"mai_NP",
"mfe_MU",
"mg_MG",
"mhr_RU",
"miq_NI",
"mi_NZ",
"mjw_IN",
"mk_MK",
"ml_IN",
"mni_IN",
"mnw_MM",
"mn_MN",
"mr_IN",
"ms_MY",
"mt_MT",
"my_MM",
"nan_TW",
"nb_NO",
"nds_DE",
"nds_NL",
"ne_NP",
"nhn_MX",
"niu_NU",
"niu_NZ",
"nl_AW",
"nl_BE",
"nl_NL",
"nn_NO",
"nr_ZA",
"nso_ZA",
"oc_FR",
"om_ET",
"om_KE",
"or_IN",
"os_RU",
"pap_AW",
"pap_CW",
"pa_IN",
"pa_PK",
"pl_PL",
"ps_AF",
"pt_BR",
"pt_PT",
"quz_PE",
"raj_IN",
"ro_RO",
"ru_RU",
"ru_UA",
"rw_RW",
"sah_RU",
"sat_IN",
"sa_IN",
"sc_IT",
"sd_IN",
"se_NO",
"sgs_LT",
"shn_MM",
"shs_CA",
"sid_ET",
"si_LK",
"sk_SK",
"sl_SI",
"sm_WS",
"so_DJ",
"so_ET",
"so_KE",
"so_SO",
"sq_AL",
"sq_MK",
"sr_ME",
"sr_RS",
"ss_ZA",
"st_ZA",
"sv_FI",
"sv_SE",
"sw_KE",
"sw_TZ",
"szl_PL",
"ta_IN",
"ta_LK",
"tcy_IN",
"te_IN",
"tg_TJ",
"the_NP",
"th_TH",
"tig_ER",
"ti_ER",
"ti_ET",
"tk_TM",
"tl_PH",
"tn_ZA",
"to_TO",
"tpi_PG",
"tr_CY",
"tr_TR",
"ts_ZA",
"tt_RU",
"ug_CN",
"uk_UA",
"unm_US",
"ur_IN",
"ur_PK",
"uz_UZ",
"ve_ZA",
"vi_VN",
"wae_CH",
"wal_ET",
"wa_BE",
"wo_SN",
"xh_ZA",
"yi_US",
"yo_NG",
"yue_HK",
"yuw_PG",
"zh_CN",
"zh_HK",
"zh_SG",
"zh_TW",
"zu_ZA" };

/* 模板

template<std::integral char_type>
inline char_type* win32_get_locale_name_from_lcid(std::uint_least32_t lcid,char_type* p) noexcept
{
	if constexpr (std::same_as<char_type, char16_t>) {
		switch (lcid)
		{
		default:
		{
			return copy_string_literal(u"C", p);
			break;
		}
		}
	}
	else
	{
		switch (lcid)
		{
		default:
		{
			return copy_string_literal(u8"C", p);
			break;
		}
		}
	}
}

*/
auto const part1 = R"(template<std::integral char_type>
inline char_type* win32_get_locale_name_from_lcid(std::uint_least32_t lcid,char_type* p) noexcept
{
	if constexpr (std::same_as<char_type, char16_t>) {
		switch (lcid)
		{
		default:
		{
			return copy_string_literal(u"C", p);
		})";

auto const part2 = R"(		}
	}
	else
	{
		switch (lcid)
		{
		default:
		{
			return copy_string_literal(u8"C", p);
		})";

auto const part3 = R"(		}
	}
})";


auto list_map = std::map<std::string, std::uint_least32_t>();

std::vector<std::pair<std::string, std::uint_least32_t>> i18n_list;
int main() {
	// 输入输出文件
	auto list_file = std::ifstream("MS-LCID.txt");
	// 将文件读入 map
	for (auto line = std::string(); getline(list_file, line);) {
		auto space = line.find(' ');
		auto length = line.length();
		auto lcid_s = line.substr(0, space);
		auto lang = line.substr(space + 1, length);
		if (space + 1 != length) {
			std::uint_least32_t lcid = stoul(lcid_s, 0, 16);
			list_map.insert({ lang, lcid });
		}
	}

	list_file.close();
	// set的迭代器的vector
	// auto set_iter_vect = std::vector<decltype(gnu_list)::iterator::value_type>();
	// 根据GNU表精准查找
	for (auto& f : gnu_list) {
		auto iter = list_map.find(f);
		if (iter != list_map.end()) {
			i18n_list.push_back({ f, iter->second });
			list_map.erase(iter);
			// set_iter_vect.push_back(f);
		}
	}
	// 从set中删去成功匹配的
	//for (auto& s : set_iter_vect) {
	//	gnu_list.erase(s);
	//}
	// set_iter_vect.clear();
	// 模糊匹配前缀
	for (auto& f : gnu_list) {
		// 模糊查找前缀
		auto pre = std::string();
		auto iter = std::find_if(list_map.begin(), list_map.end(), [&f,&pre](auto const& item) {
			// 获得MS的前缀
			auto res = f.find('_');
			pre = (res != std::string::npos) ? f.substr(0, res) : f;
			if (item.first.find(pre) != std::string::npos) {// 如果某MS前缀中有GNU前缀
				return true;
			}
			else {
				return false;
			}
			});
		if (iter != list_map.end()) {
			i18n_list.push_back({ pre, iter->second });
			list_map.erase(iter);
			// set_iter_vect.push_back(f);
		}
	}
	// 清理list
	//for (auto& s : set_iter_vect) {
	//	gnu_list.erase(s);
	//}
	//set_iter_vect.clear();
	// 输出

	auto out_code = std::ofstream("win32_get_locale_name_from_lcid.h");
	out_code << part1;
	for (auto&& [key, value] : i18n_list) {
		out_code << "\n		case " << value << ":\n		{\n			return copy_string_literal(u\"" << key << "\",p);\n		}";
	}
	out_code << "\n";
	out_code << part2;
	for (auto&& [key, value] : i18n_list) {
		out_code << "\n		case " << value << ":\n		{\n			return copy_string_literal(u8\"" << key << "\",p);\n		}";
	}
	out_code << "\n";
	out_code << part3;
	//关闭文件
	out_code.close();
}