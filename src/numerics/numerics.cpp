#include "numerics.hpp"

// ----------------------------
// https://defs.ircdocs.horse/defs/numerics.html
// ----------------------------
//
// Registration process
//
// RPL_WELCOME (001)
// RPL_YOURHOST (002)
// RPL_CREATED (003)
// RPL_MYINFO (004)
// RPL_ISUPPORT (005)
//
// --- errors ---
// ERR_NOMOTD (422)
// ----------------------------
//
// Command: CAP
// Parameters: <subcommand> [:<capabilities>]
//
// --- errors ---
//
// ----------------------------
//
// Command: PASS
// Parameters: <password>
//
// --- errors ---
// ERR_NEEDMOREPARAMS (461)
// ERR_ALREADYREGISTERED (462)
// ERR_PASSWDMISMATCH (464)
// -----------------------------
//
// Command: NICK
// Parameters: <nickname>
//
// --- errors ---
// ERR_NONICKNAMEGIVEN (431)
// ERR_ERRONEUSNICKNAME (432)
// ERR_NICKNAMEINUSE (433)
// ERR_NICKCOLLISION (436)
// -----------------------------
//
// Command: USER
// Parameters: <username> 0 * <realname>
//
// --- errors ---
// ERR_NEEDMOREPARAMS (461)
// ERR_ALREADYREGISTERED (462)
// -----------------------------
//
// Command: INVITE
//
// -----------------------------
//
// Command: JOIN
//
// -----------------------------
//
// Command: KICK
//
// -----------------------------
//
// Command: LIST
//
// -----------------------------
//
// Command: MODE
//
// -----------------------------
//
// Command: PART
//
// -----------------------------
//
// Command: PASS
//
// -----------------------------
//
// Command: PING
//
// -----------------------------
//
// Command: PRIVMSG
//
// -----------------------------
//
// Command: QUIT
//
// -----------------------------
//
// Command: TOPIC
//
// -----------------------------


const std::string& irc::numerics::rpl_welcome_001(irc::connection& conn) {

    conn.setmsg("001 " + conn.getnick() + " :Welcome to the Internet Relay Network " + conn.getnick() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_yourhost_002(irc::connection& conn) {

    conn.setmsg("002 " + conn.getnick() + " :Your host is " + irc::server::instance().getname() + ", running version " + irc::server::instance().getversion() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_created_003(irc::connection& conn) {

    conn.setmsg("003 " + conn.getnick() + " :This server was created " + irc::server::instance().getcreation() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_myinfo_004(irc::connection& conn) {

    conn.setmsg("004 " + conn.getnick() + " " + irc::server::instance().getname() + " " + irc::server::instance().getversion() + " " + irc::server::instance().getusermodes() + " " + irc::server::instance().getchannelmodes() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_isupport_005(irc::connection& conn) {

    conn.setmsg("005 " + conn.getnick() + " :are supported by this server" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_bounce_010(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_statscommands_212(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofstats_219(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_statsuptime_242(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_umodeis_221(irc::connection& conn) {
    conn.setmsg("221 " + conn.getnick() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_luserclient_251(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_luserop_252(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_luserunknown_253(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_luserchannels_254(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_luserme_255(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_adminme_256(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_adminloc1_257(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_adminloc2_258(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_adminemail_259(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_tryagain_263(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_localusers_265(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_globalusers_266(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoiscertfp_276(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_none_300(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_away_301(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_userhost_302(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_unaway_305(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_nowaway_306(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoreply_352(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoisregnick_307(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoisuser_311(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoisserver_312(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoisoperator_313(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whowasuser_314(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoisidle_317(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofwhois_318(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoischannels_319(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoisspecial_320(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_liststart_321(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_list_322(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_listend_323(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_channelmodeis_324(irc::connection& conn) {
    conn.setmsg("324 " + conn.getnick() + " " + conn.getchannelname() + " " + irc::server::instance().getchannel(conn.getchannelname()).getmode() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_creationtime_329(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoisaccount_330(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_notopic_331(irc::connection& conn) {
    conn.setmsg("331 " + conn.getnick() + " " + conn.getchannelname() + " :No topic is set" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_topic_332(irc::connection& conn) {
    conn.setmsg("332 " + conn.getnick() + " " + conn.getchannelname() + " :" + irc::server::instance().getchannel(conn.getchannelname()).gettopic() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_topicwhotime_333(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_invitelist_336(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofinvitelist_337(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoisactually_338(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_inviting_341(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_invexlist_346(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofinvexlist_347(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_exceptlist_348(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofexceptlist_349(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_version_351(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_namreply_353(irc::connection& conn) {
    conn.setmsg("353 " + conn.getnick() + " " + irc::server::instance().getchannel(conn.getchannelname()).getsymbol() + " " + conn.getchannelname() + " :" + irc::server::instance().getchannel(conn.getchannelname()).getconnectionsasstr() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofnames_366(irc::connection& conn) {
    conn.setmsg("366 " + conn.getnick() + " " + conn.getchannelname() + " :End of /NAMES list" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_links_364(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endoflinks_365(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_banlist_367(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofbanlist_368(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofwhowas_369(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_info_371(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofinfo_374(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_motdstart_375(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_motd_372(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofmotd_376(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoishost_378(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoismodes_379(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_youreoper_381(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_rehashing_382(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_time_391(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_unknownerror_400(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nosuchnick_401(irc::connection& conn) {
    conn.setmsg("401 " + conn.getnick() + " " + conn.gettarget() + " :No such nick/channel" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nosuchserver_402(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nosuchchannel_403(irc::connection& conn) {
    conn.setmsg("403 " + conn.getnick() + " " + conn.gettarget() + " :No such channel" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_cannotsendtochan_404(irc::connection& conn) {
    conn.setmsg("404 " + conn.getnick() + " " + conn.gettarget() + " :Cannot send to channel" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_toomanychannels_405(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_wasnosuchnick_406(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_noorigin_409(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_norecipient_411(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_notexttosend_412(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_inputtoolong_417(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_unknowncommand_421(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nomotd_422(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nonicknamegiven_431(irc::connection& conn) {
    conn.setmsg("431 " + conn.getnick() + " :No nickname given" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_erroneusnickname_432(irc::connection& conn) {
    conn.setmsg("432 " + conn.getnick() + " " + conn.gettarget() + " :Erroneus nickname" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nicknameinuse_433(irc::connection& conn) {
    conn.setmsg("433 " + conn.getnick() + " " + conn.gettarget() + " :Nickname is already in use" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nickcollision_436(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_usernotinchannel_441(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_notonchannel_442(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_useronchannel_443(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_notregistered_451(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_needmoreparams_461(irc::connection& conn) {
    conn.setmsg("461 " + conn.getnick() + " " + conn.gettarget() + " :Not enough parameters" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_alreadyregistered_462(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_passwdmismatch_464(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_yourebannedcreep_465(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_channelisfull_471(irc::connection& conn) {
    conn.setmsg("471 " + conn.gettarget() + " :Bad Channel Mask" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_unknownmode_472(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_inviteonlychan_473(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_bannedfromchan_474(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_badchannelkey_475(irc::connection& conn) {
    conn.setmsg("475 " + conn.getnick() + " " + conn.gettarget() + " :Cannot join channel (+k)" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_badchanmask_476(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_noprivileges_481(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_chanoprivsneeded_482(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_cantkillserver_483(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nooperhost_491(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_umodeunknownflag_501(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_usersdontmatch_502(irc::connection& conn) {
    conn.setmsg("502 " + conn.getnick() + " " + " :Cant change mode for other users" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_helpnotfound_524(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_invalidkey_525(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_starttls_670(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoissecure_671(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_starttls_691(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_invalidmodeparam_696(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_helpstart_704(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_helptxt_705(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofhelp_706(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_noprivs_723(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_loggedin_900(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_loggedout_901(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nicklocked_902(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_saslsuccess_903(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_saslfail_904(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_sasltoolong_905(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_saslaborted_906(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_saslalready_907(irc::connection& conn) {
    conn.setmsg("N/A \r\n");
    return conn.getmsg();
}

