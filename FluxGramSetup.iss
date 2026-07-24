[Setup]
AppName=FluxGram
AppVersion=1.0.0
DefaultDirName=D:\FluxGram
DefaultGroupName=FluxGram
UninstallDisplayIcon={app}\FluxGram.exe
Compression=lzma2/ultra64
SolidCompression=yes
OutputDir=D:\yarikgram\ayugram-desktop
OutputBaseFilename=FluxGramSetup

[Files]
Source: "D:\yarikgram\ayugram-desktop\FluxGram.exe"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\FluxGram"; Filename: "{app}\FluxGram.exe"
Name: "{commondesktop}\FluxGram"; Filename: "{app}\FluxGram.exe"

[Run]
Filename: "{app}\FluxGram.exe"; Description: "Run FluxGram"; Flags: postinstall nowait skipifsilent
