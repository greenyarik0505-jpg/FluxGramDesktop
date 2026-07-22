# FluxGram Desktop

```
  _____ _     _   ___  ______ _____  ___  ___  ___ 
 |  ___| |   | | | \ \/ /  _ \  ___|/ _ \/ _ \/ _ \
 | |_  | |   | | | |\  /| |_| | |_ / /_\/ /_\/ /_\ \
 |  _| | |___| |_| |/  \|  _ <|  _||  _  |  _  |  _  |
 |_|   |_____|\___//_/\_\_| \_\_|  |_| |_|_| |_|_| |_|
                                                      
```

---

## Features

- Full ghost mode (flexible)
- Messages history
- Anti-recall
- Keep locally (in group delete menu)
- Save to self (in spam report menu)
- Font customization
- Streamer mode
- Local Telegram Premium
- Translator
- Media preview & quick reaction on force click (macOS)
- Enhanced appearance

And many more.

<h3>
  <details>
    <summary>Preview</summary>
    <table>
      <tr>
        <td><img src='.github/demos/demo1.png' width='268' alt='Preferences'></td>
        <td><img src='.github/demos/demo2.png' width='268' alt='FluxGram Options'></td>
        <td><img src='.github/demos/demo3.png' width='268' alt='Message Filters'></td>
      </tr>
      <tr>
        <td><img src='.github/demos/demo4.png' width='268' alt='Appearance'></td>
        <td><img src='.github/demos/demo5.png' width='268' alt='Chats'></td>
      </tr>
    </table>
  </details>
</h3>

## Downloads

### Windows

#### Official

You can download prebuilt Windows binary from [Releases tab](https://github.com/greenyarik0505-jpg/FluxGramDesktop/releases).

#### Winget

```bash
winget install RadolynLabs.FluxGramDesktop
```

#### Scoop

```bash
scoop bucket add extras
scoop install fluxgram
```

#### Self-built

Follow [official guide](https://github.com/greenyarik0505-jpg/FluxGramDesktop/blob/dev/docs/building-win-x64.md) if you want to
build by yourself.

### macOS

#### Official

You can download prebuilt macOS package from [Releases tab](https://github.com/greenyarik0505-jpg/FluxGramDesktop/releases).

#### Homebrew

```bash
brew install --cask fluxgram
```

### Arch Linux

#### From source (recommended)

Install `fluxgram-desktop` from [AUR](https://aur.archlinux.org/packages/fluxgram-desktop).

#### Prebuilt binaries

Install `fluxgram-desktop-bin` from [AUR](https://aur.archlinux.org/packages/fluxgram-desktop-bin).

Note: these binaries aren't officially maintained by us.

### NixOS

#### Flake (recommended)

Install `fluxgram-desktop` from [ndfined-crp/ayugram-desktop](https://github.com/ndfined-crp/ayugram-desktop)

#### Nixpkgs

Install `fluxgram-desktop` from [nixpkgs](https://search.nixos.org/packages?channel=unstable&show=ayugram-desktop)

### ALT Linux

[Sisyphus](https://packages.altlinux.org/en/sisyphus/srpms/ayugram-desktop/)

### Gentoo Linux

See [this repository](https://codeberg.org/OverLessArtem/ayugram-ebuild-gentoo) for installation manual.

### Void Linux
See [this repository](https://codeberg.org/OverLessArtem/ayugram-template-void) for installation manual.

### EPM

`epm play fluxgram`

### Fedora

From [RPM Fusion](https://admin.rpmfusion.org/pkgdb/package/free/ayugram-desktop/) repository.

```bash
dnf install fluxgram-desktop
```

### Any other Linux distro

Flatpak: https://github.com/0FL01/AyuGramDesktop-flatpak

Or follow the [official guide](https://github.com/greenyarik0505-jpg/FluxGramDesktop/blob/dev/docs/building-linux.md).

### Remarks for Windows

Make sure you have these components installed with VS Build Tools:

- C++ MFC latest (x86 & x64)
- C++ ATL latest (x86 & x64)
- latest Windows 11 SDK

## Credits

### Telegram clients

- [Telegram Desktop](https://github.com/telegramdesktop/tdesktop)
- [Kotatogram](https://github.com/kotatogram/kotatogram-desktop)
- [64Gram](https://github.com/TDesktop-x64/tdesktop)
- [Forkgram](https://github.com/forkgram/tdesktop)

### Libraries used

- [JSON for Modern C++](https://github.com/nlohmann/json)
- [SQLite](https://github.com/sqlite/sqlite)
- [sqlite_orm](https://github.com/fnc12/sqlite_orm)
- [androidx sources](https://github.com/androidx/androidx)

### Icons

- [Solar Icon Set](https://www.figma.com/community/file/1166831539721848736)

### Bots

- [TelegramDB](https://t.me/tgdatabase) for username lookup by ID (until closing free inline mode at 2 April 2026)
