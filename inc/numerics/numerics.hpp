#ifndef NUMERICS_HEADER
# define NUMERICS_HEADER

# include <string>
# include "server.hpp"


// -- I R C  N A M E S P A C E ------------------------------------------------

namespace irc {


	// -- N U M E R I C S  N A M E S P A C E ----------------------------------

	namespace numerics {

        const std::string& rpl_welcome_001(irc::connection& conn);
        const std::string& rpl_yourhost_002(irc::connection& conn);
        const std::string& rpl_created_003(irc::connection& conn);
        const std::string& rpl_myinfo_004(irc::connection& conn);
        const std::string& rpl_isupport_005(irc::connection& conn);
        const std::string& rpl_bounce_010(irc::connection& conn);
        const std::string& rpl_statscommands_212(irc::connection& conn);
        const std::string& rpl_endofstats_219(irc::connection& conn);
        const std::string& rpl_statsuptime_242(irc::connection& conn);
        const std::string& rpl_umodeis_221(irc::connection& conn);
        const std::string& rpl_luserclient_251(irc::connection& conn);
        const std::string& rpl_luserop_252(irc::connection& conn);
        const std::string& rpl_luserunknown_253(irc::connection& conn);
        const std::string& rpl_luserchannels_254(irc::connection& conn);
        const std::string& rpl_luserme_255(irc::connection& conn);
        const std::string& rpl_adminme_256(irc::connection& conn);
        const std::string& rpl_adminloc1_257(irc::connection& conn);
        const std::string& rpl_adminloc2_258(irc::connection& conn);
        const std::string& rpl_adminemail_259(irc::connection& conn);
        const std::string& rpl_tryagain_263(irc::connection& conn);
        const std::string& rpl_localusers_265(irc::connection& conn);
        const std::string& rpl_globalusers_266(irc::connection& conn);
        const std::string& rpl_whoiscertfp_276(irc::connection& conn);
        const std::string& rpl_none_300(irc::connection& conn);
        const std::string& rpl_away_301(irc::connection& conn);
        const std::string& rpl_userhost_302(irc::connection& conn);
        const std::string& rpl_unaway_305(irc::connection& conn);
        const std::string& rpl_nowaway_306(irc::connection& conn);
        const std::string& rpl_whoreply_352(irc::connection& conn);
        const std::string& rpl_whoisregnick_307(irc::connection& conn);
        const std::string& rpl_whoisuser_311(irc::connection& conn);
        const std::string& rpl_whoisserver_312(irc::connection& conn);
        const std::string& rpl_whoisoperator_313(irc::connection& conn);
        const std::string& rpl_whowasuser_314(irc::connection& conn);
        const std::string& rpl_whoisidle_317(irc::connection& conn);
        const std::string& rpl_endofwhois_318(irc::connection& conn);
        const std::string& rpl_whoischannels_319(irc::connection& conn);
        const std::string& rpl_whoisspecial_320(irc::connection& conn);
        const std::string& rpl_liststart_321(irc::connection& conn);
        const std::string& rpl_list_322(irc::connection& conn);
        const std::string& rpl_listend_323(irc::connection& conn);
        const std::string& rpl_channelmodeis_324(irc::connection& conn);
        const std::string& rpl_creationtime_329(irc::connection& conn);
        const std::string& rpl_whoisaccount_330(irc::connection& conn);
        const std::string& rpl_notopic_331(irc::connection& conn);
        const std::string& rpl_topic_332(irc::connection& conn);
        const std::string& rpl_topicwhotime_333(irc::connection& conn);
        const std::string& rpl_invitelist_336(irc::connection& conn);
        const std::string& rpl_endofinvitelist_337(irc::connection& conn);
        const std::string& rpl_whoisactually_338(irc::connection& conn);
        const std::string& rpl_inviting_341(irc::connection& conn);
        const std::string& rpl_invexlist_346(irc::connection& conn);
        const std::string& rpl_endofinvexlist_347(irc::connection& conn);
        const std::string& rpl_exceptlist_348(irc::connection& conn);
        const std::string& rpl_endofexceptlist_349(irc::connection& conn);
        const std::string& rpl_version_351(irc::connection& conn);
        const std::string& rpl_namreply_353(irc::connection& conn);
        const std::string& rpl_endofnames_366(irc::connection& conn);
        const std::string& rpl_links_364(irc::connection& conn);
        const std::string& rpl_endoflinks_365(irc::connection& conn);
        const std::string& rpl_banlist_367(irc::connection& conn);
        const std::string& rpl_endofbanlist_368(irc::connection& conn);
        const std::string& rpl_endofwhowas_369(irc::connection& conn);
        const std::string& rpl_info_371(irc::connection& conn);
        const std::string& rpl_endofinfo_374(irc::connection& conn);
        const std::string& rpl_motdstart_375(irc::connection& conn);
        const std::string& rpl_motd_372(irc::connection& conn);
        const std::string& rpl_endofmotd_376(irc::connection& conn);
        const std::string& rpl_whoishost_378(irc::connection& conn);
        const std::string& rpl_whoismodes_379(irc::connection& conn);
        const std::string& rpl_youreoper_381(irc::connection& conn);
        const std::string& rpl_rehashing_382(irc::connection& conn);
        const std::string& rpl_time_391(irc::connection& conn);
        const std::string& err_unknownerror_400(irc::connection& conn);
        const std::string& err_nosuchnick_401(irc::connection& conn);
        const std::string& err_nosuchserver_402(irc::connection& conn);
        const std::string& err_nosuchchannel_403(irc::connection& conn);
        const std::string& err_cannotsendtochan_404(irc::connection& conn);
        const std::string& err_toomanychannels_405(irc::connection& conn);
        const std::string& err_wasnosuchnick_406(irc::connection& conn);
        const std::string& err_noorigin_409(irc::connection& conn);
        const std::string& err_norecipient_411(irc::connection& conn);
        const std::string& err_notexttosend_412(irc::connection& conn);
        const std::string& err_inputtoolong_417(irc::connection& conn);
        const std::string& err_unknowncommand_421(irc::connection& conn);
        const std::string& err_nomotd_422(irc::connection& conn);
        const std::string& err_nonicknamegiven_431(irc::connection& conn);
        const std::string& err_erroneusnickname_432(irc::connection& conn);
        const std::string& err_nicknameinuse_433(irc::connection& conn);
        const std::string& err_nickcollision_436(irc::connection& conn);
        const std::string& err_usernotinchannel_441(irc::connection& conn);
        const std::string& err_notonchannel_442(irc::connection& conn);
        const std::string& err_useronchannel_443(irc::connection& conn);
        const std::string& err_notregistered_451(irc::connection& conn);
        const std::string& err_needmoreparams_461(irc::connection& conn);
        const std::string& err_alreadyregistered_462(irc::connection& conn);
        const std::string& err_passwdmismatch_464(irc::connection& conn);
        const std::string& err_yourebannedcreep_465(irc::connection& conn);
        const std::string& err_channelisfull_471(irc::connection& conn);
        const std::string& err_unknownmode_472(irc::connection& conn);
        const std::string& err_inviteonlychan_473(irc::connection& conn);
        const std::string& err_bannedfromchan_474(irc::connection& conn);
        const std::string& err_badchannelkey_475(irc::connection& conn);
        const std::string& err_badchanmask_476(irc::connection& conn);
        const std::string& err_noprivileges_481(irc::connection& conn);
        const std::string& err_chanoprivsneeded_482(irc::connection& conn);
        const std::string& err_cantkillserver_483(irc::connection& conn);
        const std::string& err_nooperhost_491(irc::connection& conn);
        const std::string& err_umodeunknownflag_501(irc::connection& conn);
        const std::string& err_usersdontmatch_502(irc::connection& conn);
        const std::string& err_helpnotfound_524(irc::connection& conn);
        const std::string& err_invalidkey_525(irc::connection& conn);
        const std::string& rpl_starttls_670(irc::connection& conn);
        const std::string& rpl_whoissecure_671(irc::connection& conn);
        const std::string& err_starttls_691(irc::connection& conn);
        const std::string& err_invalidmodeparam_696(irc::connection& conn);
        const std::string& rpl_helpstart_704(irc::connection& conn);
        const std::string& rpl_helptxt_705(irc::connection& conn);
        const std::string& rpl_endofhelp_706(irc::connection& conn);
        const std::string& err_noprivs_723(irc::connection& conn);
        const std::string& rpl_loggedin_900(irc::connection& conn);
        const std::string& rpl_loggedout_901(irc::connection& conn);
        const std::string& err_nicklocked_902(irc::connection& conn);
        const std::string& rpl_saslsuccess_903(irc::connection& conn);
        const std::string& err_saslfail_904(irc::connection& conn);
        const std::string& err_sasltoolong_905(irc::connection& conn);
        const std::string& err_saslaborted_906(irc::connection& conn);
        const std::string& err_saslalready_907(irc::connection& conn);

    }
}

#endif
