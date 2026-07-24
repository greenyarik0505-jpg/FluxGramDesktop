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
	QFile::copy(qsl(":/gui/art/ayu/%1/app_icon.ico").arg(settings.appIcon()), iconPath);
}

// Draws a raster image (PNG/JPEG/any Qt-supported format or resource) centered
// into a transparent canvas of the requested size. Used both for bundled
// raster icons and for the guaranteed fallback logo.
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
		p.drawImage(
			QRect(padding, padding, iconSize.width(), iconSize.height()),
			loaded);
	}
	return res;
}

QImage CreateImage(const QString &name, const QSize resultImageSize, const int padding = 0) {
	const auto iconSize = resultImageSize.shrunkBy(QMargins(padding, padding, padding, padding));

	// Guarantees the app never shows a blank icon if a theme asset is missing
	// or mislabeled (some bundled "*.svg" files are actually raster images).
	const auto fallback = qsl(":/gui/art/logo_256.png");

	const auto pngPath = qsl(":/gui/art/ayu/%1/app.png").arg(name);
	if (QFile::exists(pngPath) && !QImage(pngPath).isNull()) {
		return CreateRaster(pngPath, resultImageSize, padding);
	}

	const auto svgPath = qsl(":/gui/art/ayu/%1/app.svg").arg(name);
	if (QFile::exists(svgPath)) {
		auto svg = QSvgRenderer(svgPath);
		if (svg.isValid()) {
			auto image = QImage(
				resultImageSize * style::DevicePixelRatio(),
				QImage::Format_ARGB32_Premultiplied);
			image.setDevicePixelRatio(style::DevicePixelRatio());
			image.fill(Qt::transparent);
			{
				auto p = QPainter(&image);

				QPainterPath path;
				path.addRoundedRect(
					QRect(padding, padding, iconSize.width(), iconSize.height()),
					iconSize.width() / 2.0f,
					iconSize.height() / 2.0f
				);

				p.save();

				p.setRenderHint(QPainter::Antialiasing, true);
				p.setClipPath(path);
				p.setRenderHint(QPainter::Antialiasing, false);

				svg.render(&p, QRect(padding, padding, iconSize.width(), iconSize.height()));

				p.restore();
			}
			return image;
		}
	}

	// Missing or non-SVG asset (e.g. a JPEG mislabeled as .svg) — fall back to
	// the guaranteed-valid bundled FluxGram logo instead of a blank icon.
	return CreateRaster(fallback, resultImageSize, padding);
}

void loadIcons() {
	const auto &settings = AyuSettings::getInstance();
	if (LAST_LOADED_NAME != settings.appIcon()) {
		LAST_LOADED_NAME = settings.appIcon();
		LAST_LOADED = CreateImage(settings.appIcon(), Size(256));
		LAST_LOADED_PAD = CreateImage(settings.appIcon(), Size(256), 12);
	}
}

QImage loadPreview(const QString &name) {
	return CreateImage(name, Size(st::iconPickerIconSize), st::iconPickerImagePadding);
}

QString currentAppLogoName() {
	return LAST_LOADED_NAME;
}

QImage currentAppLogo() {
	loadIcons();
	return LAST_LOADED;
}

QImage currentAppLogoPad() {
	loadIcons();
	return LAST_LOADED_PAD;
}

}
