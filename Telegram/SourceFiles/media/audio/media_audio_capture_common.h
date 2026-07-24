/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Media::Capture {

struct Result {
	QByteArray bytes;
	VoiceWaveform waveform;
	crl::time duration;
	bool video = false;
};

} // namespace Media::Capture

