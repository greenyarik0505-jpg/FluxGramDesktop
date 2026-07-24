/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Calls::Group {

struct PreparedMessage {
	uint64 randomId = 0;
	MTPTextWithEntities message;
};

[[nodiscard]] QByteArray SerializeMessage(const PreparedMessage &data);
[[nodiscard]] std::optional<PreparedMessage> DeserializeMessage(
	const QByteArray &data);

} // namespace Calls::Group

