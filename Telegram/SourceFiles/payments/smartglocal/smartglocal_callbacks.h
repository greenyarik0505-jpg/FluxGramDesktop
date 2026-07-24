/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include <functional>

namespace SmartGlocal {

class Token;
class Error;

using TokenCompletionCallback = std::function<void(Token, Error)>;

} // namespace SmartGlocal

