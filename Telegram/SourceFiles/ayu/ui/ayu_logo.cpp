// This is the source code of FluxGram for Desktop.
//
// We do not and cannot prevent the use of our code,
// but be respectful and credit the original author.
//
// Copyright @Radolyn, 2026
#include "ayu/ui/ayu_logo.h"

#include "ayu/ayu_settings.h"
#include "styles/style_ayu_styles.h"
#include "ui/rect.h"

#include <QSvgRenderer>

static QString LAST_LOADED_NAME;
static QImage LAST_LOADED;
static QImage LAST_LOADED_PAD;

namespace AyuAssets {

QString appIcoPath() {
	const auto &settings = AyuSettings::getInstance();
	return cWorkingDir()
		+ u"tdata/FluxGram-"_q
		+ settings.appIcon()
		+ u".ico"_q;
}

void loadAppIco() {
	const auto &settings = AyuSettings::getInstance();
	const auto iconPath = appIcoPath();

	auto f = QFile(iconPath);
	if (f.exists()) {
		f.setPermissions(QFile::WriteOther);
		f.remove();
	}
	f.close();
	QFile::copy(qsl(":/gui/art/icon256.ico"), iconPath);
}

QImage CreateRaster(
		const QString &source,
		const QSize resultImageSize,
		const int padding) {
	const auto iconSize = resultImageSize.shrunkBy(
		QMargins(padding, padding, padding, padding));
	const auto loaded = QImage(source).scaled(
		iconSize,
		Qt::KeepAspectRatio,
		Qt::SmoothTransformation);
	auto res = QImage(
		resultImageSize * style::DevicePixelRatio(),
		QImage::Format_ARGB32_Premultiplied);
	res.setDevicePixelRatio(style::DevicePixelRatio());
	res.fill(Qt::transparent);
	if (!loaded.isNull()) {
		auto p = QPainter(&res);
		p.setRenderHint(QPainter::Antialiasing, true);
		p.setRenderHint(QPainter::SmoothPixmapTransform, true);
		const auto targetRect = QRect(
			padding + (iconSize.width() - loaded.width() / style::DevicePixelRatio()) / 2,
			padding + (iconSize.height() - loaded.height() / style::DevicePixelRatio()) / 2,
			loaded.width() / style::DevicePixelRatio(),
			loaded.height() / style::DevicePixelRatio());
		p.drawImage(targetRect, loaded);
	}
	return res;
}

QImage CreateImage(const QString &name, const QSize resultImageSize, const int padding = 0) {
	const auto pngPath = qsl(":/gui/art/icon512.png");
	if (QFile::exists(pngPath) && !QImage(pngPath).isNull()) {
		return CreateRaster(pngPath, resultImageSize, padding);
	}

	const auto fallback = qsl(":/gui/art/logo_256.png");
	return CreateRaster(fallback, resultImageSize, padding);
}

QImage currentAppLogo(const QSize &size) {
	const auto &settings = AyuSettings::getInstance();
	if (LAST_LOADED_NAME != settings.appIcon()) {
		LAST_LOADED_NAME = settings.appIcon();
		LAST_LOADED = QImage();
		LAST_LOADED_PAD = QImage();
	}
	if (LAST_LOADED.isNull()) {
		LAST_LOADED = CreateImage(settings.appIcon(), QSize(256, 256));
	}
	return LAST_LOADED.scaled(
		size * style::DevicePixelRatio(),
		Qt::KeepAspectRatio,
		Qt::SmoothTransformation);
}

QImage currentAppLogoWithPadding(const QSize &size) {
	const auto &settings = AyuSettings::getInstance();
	if (LAST_LOADED_NAME != settings.appIcon()) {
		LAST_LOADED_NAME = settings.appIcon();
		LAST_LOADED = QImage();
		LAST_LOADED_PAD = QImage();
	}
	if (LAST_LOADED_PAD.isNull()) {
		LAST_LOADED_PAD = CreateImage(settings.appIcon(), QSize(256, 256), st::ayu_logo_padding);
	}
	return LAST_LOADED_PAD.scaled(
		size * style::DevicePixelRatio(),
		Qt::KeepAspectRatio,
		Qt::SmoothTransformation);
}

} // namespace AyuAssets
