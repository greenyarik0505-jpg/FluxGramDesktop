/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "base/object_ptr.h"

namespace Ui {

class RpWidget;

[[nodiscard]] object_ptr<RpWidget> CreateOutdatedBar(
	not_null<QWidget*> parent,
	const QString &workingPath);

} // namespace Ui

