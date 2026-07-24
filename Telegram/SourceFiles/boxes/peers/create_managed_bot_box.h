/*
This file is part of FluxGram,
the official desktop application for the FluxGram messaging service.

For license and copyright information please follow this link:
https://github.com/FluxGramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

class UserData;

namespace Main {
class SessionShow;
} // namespace Main

namespace Ui {
class GenericBox;
} // namespace Ui

struct CreateManagedBotDescriptor {
	std::shared_ptr<Main::SessionShow> show;
	not_null<UserData*> manager;
	QString suggestedName;
	QString suggestedUsername;
	bool viaDeeplink = false;
	Fn<void(not_null<UserData*>)> done;
	Fn<void()> cancelled;
};

void CreateManagedBotBox(
	not_null<Ui::GenericBox*> box,
	CreateManagedBotDescriptor &&descriptor);

void ShowCreateManagedBotBox(CreateManagedBotDescriptor &&descriptor);

