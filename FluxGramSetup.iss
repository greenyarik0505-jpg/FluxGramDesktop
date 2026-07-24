[Setup]
AppName=FluxGram Desktop
AppVersion=1.0.13
AppPublisher=FluxGram Team
AppPublisherURL=https://github.com/greenyarik0505-jpg/FluxGramDesktop
DefaultDirName={autopf}\FluxGram
DefaultGroupName=FluxGram Desktop
UninstallDisplayIcon={app}\icon256.ico
SetupIconFile=Telegram\Resources\art\icon256.ico
Compression=lzma2/max
SolidCompression=yes
OutputDir=.
OutputBaseFilename=FluxGramSetup

[Files]
Source: "FluxGram.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "Telegram\Resources\art\icon256.ico"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\FluxGram Desktop"; Filename: "{app}\FluxGram.exe"; IconFilename: "{app}\icon256.ico"; WorkingDir: "{app}"; AppUserModelID: "FluxGram.FluxGramDesktop"
Name: "{autodesktop}\FluxGram Desktop"; Filename: "{app}\FluxGram.exe"; IconFilename: "{app}\icon256.ico"; WorkingDir: "{app}"; AppUserModelID: "FluxGram.FluxGramDesktop"

[Run]
Filename: "{app}\FluxGram.exe"; Description: "Run FluxGram Desktop"; Flags: postinstall nowait skipifsilent
