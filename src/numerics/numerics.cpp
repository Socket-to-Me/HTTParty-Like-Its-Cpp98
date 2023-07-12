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

    conn.setmsg(":" + irc::server::instance().getname() + " 001 " + conn.getnick() + " :Welcome to the Internet Relay Network " + conn.getnick() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_yourhost_002(irc::connection& conn) {

    conn.setmsg(":" + irc::server::instance().getname() + " 002 " + conn.getnick() + " :Your host is " + irc::server::instance().getname() + ", running version " + irc::server::instance().getversion() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_created_003(irc::connection& conn) {

    conn.setmsg(":" + irc::server::instance().getname() + " 003 " + conn.getnick() + " :This server was created " + irc::server::instance().getcreation() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_myinfo_004(irc::connection& conn) {

    conn.setmsg(":" + irc::server::instance().getname() + " 004 " + conn.getnick() + " " + irc::server::instance().getname() + " " + irc::server::instance().getversion() + " " + irc::server::instance().getusermodes() + " " + irc::server::instance().getchannelmodes() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_isupport_005(irc::connection& conn) {

    conn.setmsg(":" + irc::server::instance().getname() + " 005 " + conn.getnick() + " CASEMAPPING=ascii NICKLEN=15 CHANTYPES=# :are supported by this server" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_umodeis_221(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 221 " + conn.getnick() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_whoreply_352(irc::connection& conn) {

    irc::server&        serv = irc::server::instance();
    irc::channel&       channel = serv.getchannel(conn.getchannelname());
    irc::connection&    usr = serv.getconnection(conn.gettarget());
    std::string         opflag;

    if (channel.isOperator(usr)) {
        opflag = "*";
    }

    conn.setmsg(":" + irc::server::instance().getname() + " 352 " + conn.getnick() + " " + conn.getchannelname() + " " + usr.getuser() + " " + usr.gethost() + " " + serv.getname() + " " + usr.getnick() + " H" + opflag + " :0 " + usr.getrealname() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofwho_315(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 315 " + conn.getnick() + " " + conn.gettarget() + " :End of WHO list" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_channelmodeis_324(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 324 " + conn.getnick() + " " + conn.getchannelname() + " " + irc::server::instance().getchannel(conn.getchannelname()).getmode() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_notopic_331(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 331 " + conn.getnick() + " " + conn.getchannelname() + " :No topic is set" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_topic_332(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 332 " + conn.getnick() + " " + conn.getchannelname() + " :" + irc::server::instance().getchannel(conn.getchannelname()).gettopic() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_inviting_341(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 341 " + conn.getnick() + " " + conn.getchannelname() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_namreply_353(irc::connection& conn) {
    irc::channel&   channel = irc::server::instance().getchannel(conn.getchannelname());
    conn.setmsg(":" + irc::server::instance().getname() + " 353 " + conn.getnick() + " " + channel.getsymbol() + " " + conn.getchannelname() + " :" + channel.getconnectionsasstr() + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::rpl_endofnames_366(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 366 " + conn.getnick() + " " + conn.getchannelname() + " :End of /NAMES list" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nosuchnick_401(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 401 " + conn.getnick() + " " + conn.gettarget() + " :No such nick/channel" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nosuchchannel_403(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 403 " + conn.getnick() + " " + conn.gettarget() + " :No such channel" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_cannotsendtochan_404(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 404 " + conn.getnick() + " " + conn.gettarget() + " :Cannot send to channel" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nonicknamegiven_431(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 431 " + conn.getnick() + " :No nickname given" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_erroneusnickname_432(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 432 " + conn.getnick() + " " + conn.gettarget() + " :Erroneus nickname" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_nicknameinuse_433(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 433 " + conn.gettarget() + " :Nickname is already in use" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_usernotinchannel_441(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 441 " + conn.getnick() + " " + conn.gettarget() + " " + conn.getchannelname() + " :They aren't on that channel" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_notonchannel_442(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 442 " + conn.getnick() + " " + conn.gettarget() + " :You're not on that channel" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_useronchannel_443(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 443 * " + conn.getnick() + " " + conn.gettarget() + " " + conn.getchannelname() + " :is already on channel" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_needmoreparams_461(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 461 " + conn.getnick() + " " + conn.gettarget() + " :Not enough parameters" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_alreadyregistered_462(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 462 " + conn.getnick() + " :You may not reregister" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_passwdmismatch_464(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 464 " + conn.getnick() + " :Password incorrect" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_channelisfull_471(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 471 " + conn.getnick() + " " + conn.gettarget() + " :Cannot join channel (+l)" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_unknownmode_472(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 472 " + conn.getnick() + " " + conn.gettarget() + " :is unknown mode char to me" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_inviteonlychan_473(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 473 " + conn.getnick() + " " + conn.gettarget() + " :Cannot join channel (+i)" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_badchannelkey_475(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 475 " + conn.getnick() + " " + conn.gettarget() + " :Cannot join channel (+k)" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_badchanmask_476(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 476 " + conn.gettarget() + " :Bad Channel Mask" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_chanoprivsneeded_482(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 482 " + conn.getnick() + " " + conn.gettarget() + " :You're not channel operator" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_umodeunknownflag_501(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 501 " + conn.getnick() + " :Unknown MODE flag" + "\r\n");
    return conn.getmsg();
}

const std::string& irc::numerics::err_usersdontmatch_502(irc::connection& conn) {
    conn.setmsg(":" + irc::server::instance().getname() + " 502 " + conn.getnick() + " :Cant change mode for other users" + "\r\n");
    return conn.getmsg();
}
