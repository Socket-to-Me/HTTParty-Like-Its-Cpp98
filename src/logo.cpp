#include "logo.hpp"

const std::string irc::logo::_logo = irc::logo::init_logo();

std::string irc::logo::init_logo(void) {

	const char* lines[] = {
		"",
		"      ::::::::::: :::::::::   ::::::::          ::::::::  :::::::::: :::::::::  :::     ::: :::::::::: :::::::::",
		"         :+:     :+:    :+: :+:    :+:        :+:    :+: :+:        :+:    :+: :+:     :+: :+:        :+:    :+:",
		"        +:+     +:+    +:+ +:+               +:+        +:+        +:+    +:+ +:+     +:+ +:+        +:+    +:+",
		"       +#+     +#++:++#:  +#+               +#++:++#++ +#++:++#   +#++:++#:  +#+     +:+ +#++:++#   +#++:++#:",
		"      +#+     +#+    +#+ +#+                      +#+ +#+        +#+    +#+  +#+   +#+  +#+        +#+    +#+",
		"     #+#     #+#    #+# #+#    #+#        #+#    #+# #+#        #+#    #+#   #+#+#+#   #+#        #+#    #+#",
		"########### ###    ###  ########          ########  ########## ###    ###     ###     ########## ###    ###",
		static_cast<const char*>(0)
	};

	std::string logo;

	for (std::size_t i = 0; lines[i]; ++i) {
		logo.append(lines[i]);
		logo.push_back('\n');
	}
	return logo;
}

const std::string& irc::logo::get(void) {
	return _logo;
}

