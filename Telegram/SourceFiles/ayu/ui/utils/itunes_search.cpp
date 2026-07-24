// This is the source code of FluxGram for Desktop.
//
// We do not and cannot prevent the use of our code,
// but be respectful and credit the original author.
//
// Copyright @Radolyn, 2026
#include "ayu/ui/utils/itunes_search.h"

#include <QtCore/QCache>
#include <QtCore/QEventLoop>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QRegularExpression>
#include <QtCore/QTimer>
#include <QtCore/QUrlQuery>
#include <QtGui/QImage>
#include <QtGui/QPixmap>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

namespace Ayu::Ui::Itunes {
namespace {

struct CacheEntry
{
	QPixmap pix;
};

QCache<QString, CacheEntry> &cache() {
	static QCache<QString, CacheEntry> c(50);
	return c;
}

QString translitSafe(const QString &s) {
	static const QHash<QChar, QString> trMap = []
	{
		QHash<QChar, QString> m;
		m.reserve(487); // 488
		m.insert(QChar(u'?'), QStringLiteral("c"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u'y'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("k"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("aa"));
		m.insert(QChar(u'?'), QStringLiteral("ij"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("b"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'e'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("ffi"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'i'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("p"));
		m.insert(QChar(u'y'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("b"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("c"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u'?'), QStringLiteral("b"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'd'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("j"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("v"));
		m.insert(QChar(u'?'), QStringLiteral("p"));
		m.insert(QChar(u'?'), QStringLiteral("fi"));
		m.insert(QChar(u'?'), QStringLiteral("k"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'e'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("k"));
		m.insert(QChar(u'c'), QStringLiteral("c"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("hv"));
		m.insert(QChar(u'b'), QStringLiteral("b"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("ou"));
		m.insert(QChar(u'j'), QStringLiteral("j"));
		m.insert(QChar(u'?'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("j"));
		m.insert(QChar(u'g'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("dz"));
		m.insert(QChar(u'z'), QStringLiteral("z"));
		m.insert(QChar(u'?'), QStringLiteral("au"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'a'), QStringLiteral("a"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'a'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("fl"));
		m.insert(QChar(u'?'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'i'), QStringLiteral("i"));
		m.insert(QChar(u'n'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'?'), QStringLiteral("z"));
		m.insert(QChar(u'?'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'g'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("k"));
		m.insert(QChar(u'?'), QStringLiteral("et"));
		m.insert(QChar(u'i'), QStringLiteral("i"));
		m.insert(QChar(u't'), QStringLiteral("t"));
		m.insert(QChar(u'?'), QStringLiteral("c"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("av"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("ae"));
		m.insert(QChar(u'a'), QStringLiteral("a"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("b"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u'?'), QStringLiteral("x"));
		m.insert(QChar(u'?'), QStringLiteral("k"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("oi"));
		m.insert(QChar(u'?'), QStringLiteral("p"));
		m.insert(QChar(u'h'), QStringLiteral("h"));
		m.insert(QChar(u'?'), QStringLiteral("v"));
		m.insert(QChar(u'?'), QStringLiteral("w"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("m"));
		m.insert(QChar(u'?'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("p"));
		m.insert(QChar(u'?'), QStringLiteral("v"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("b"));
		m.insert(QChar(u'?'), QStringLiteral("p"));
		m.insert(QChar(u'a'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("c"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("f"));
		m.insert(QChar(u'?'), QStringLiteral("ae"));
		m.insert(QChar(u'?'), QStringLiteral("vy"));
		m.insert(QChar(u'?'), QStringLiteral("ff"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("z"));
		m.insert(QChar(u'?'), QStringLiteral("f"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("q"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'k'), QStringLiteral("k"));
		m.insert(QChar(u'i'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u't'), QStringLiteral("t"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("k"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'?'), QStringLiteral("q"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("j"));
		m.insert(QChar(u'l'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("f"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("v"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("c"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("z"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'n'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("w"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("lj"));
		m.insert(QChar(u'?'), QStringLiteral("b"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("w"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("ay"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("b"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'i'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'e'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("m"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		m.insert(QChar(u'e'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("i"));
		m.insert(QChar(u'd'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("m"));
		m.insert(QChar(u'?'), QStringLiteral("y"));
		m.insert(QChar(u'w'), QStringLiteral("w"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("z"));
		m.insert(QChar(u'j'), QStringLiteral("j"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("j"));
		m.insert(QChar(u'e'), QStringLiteral("e"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'g'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'k'), QStringLiteral("k"));
		m.insert(QChar(u'?'), QStringLiteral("ae"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("m"));
		m.insert(QChar(u'?'), QStringLiteral("f"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("oo"));
		m.insert(QChar(u'?'), QStringLiteral("m"));
		m.insert(QChar(u'?'), QStringLiteral("p"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("k"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u't'), QStringLiteral("t"));
		m.insert(QChar(u'?'), QStringLiteral("p"));
		m.insert(QChar(u'?'), QStringLiteral("m"));
		m.insert(QChar(u'a'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("v"));
		m.insert(QChar(u'e'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("z"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("p"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("z"));
		m.insert(QChar(u'?'), QStringLiteral("m"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("v"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("ss"));
		m.insert(QChar(u'h'), QStringLiteral("h"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'?'), QStringLiteral("z"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'a'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("oe"));
		m.insert(QChar(u'?'), QStringLiteral("x"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("j"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("z"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("ao"));
		m.insert(QChar(u'?'), QStringLiteral("z"));
		m.insert(QChar(u'y'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("b"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'?'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("j"));
		m.insert(QChar(u'?'), QStringLiteral("z"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u'?'), QStringLiteral("w"));
		m.insert(QChar(u'?'), QStringLiteral("k"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'i'), QStringLiteral("i"));
		m.insert(QChar(u'g'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("q"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'?'), QStringLiteral("um"));
		m.insert(QChar(u'?'), QStringLiteral("c"));
		m.insert(QChar(u'?'), QStringLiteral("x"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u's'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("nj"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'l'), QStringLiteral("l"));
		m.insert(QChar(u'z'), QStringLiteral("z"));
		m.insert(QChar(u'?'), QStringLiteral("th"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u's'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("v"));
		m.insert(QChar(u'?'), QStringLiteral("is"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("ffl"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("ue"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("z"));
		m.insert(QChar(u'?'), QStringLiteral("w"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'g'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'a'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'?'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("ae"));
		m.insert(QChar(u'?'), QStringLiteral("v"));
		m.insert(QChar(u'?'), QStringLiteral("oe"));
		m.insert(QChar(u'?'), QStringLiteral("m"));
		m.insert(QChar(u'z'), QStringLiteral("z"));
		m.insert(QChar(u'e'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("av"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("st"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'r'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("ou"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'a'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'c'), QStringLiteral("c"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'g'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("k"));
		m.insert(QChar(u'?'), QStringLiteral("z"));
		m.insert(QChar(u's'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("f"));
		m.insert(QChar(u'?'), QStringLiteral("x"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		m.insert(QChar(u'e'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u't'), QStringLiteral("t"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		// m.insert(QChar(u'i?'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'c'), QStringLiteral("c"));
		m.insert(QChar(u'?'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("w"));
		m.insert(QChar(u'?'), QStringLiteral("d"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("oe"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'l'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("ae"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'a'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("p"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'i'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("dz"));
		m.insert(QChar(u'?'), QStringLiteral("g"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		m.insert(QChar(u'l'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("w"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'n'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("b"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("f"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("p"));
		m.insert(QChar(u'?'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'a'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("u"));
		m.insert(QChar(u'i'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("g"));
		m.insert(QChar(u'r'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u'u'), QStringLiteral("u"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u'?'), QStringLiteral("t"));
		m.insert(QChar(u'n'), QStringLiteral("n"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'i'), QStringLiteral("i"));
		m.insert(QChar(u'?'), QStringLiteral("w"));
		m.insert(QChar(u'e'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'l'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("l"));
		m.insert(QChar(u'?'), QStringLiteral("y"));
		m.insert(QChar(u'?'), QStringLiteral("j"));
		m.insert(QChar(u'?'), QStringLiteral("k"));
		m.insert(QChar(u'?'), QStringLiteral("v"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'a'), QStringLiteral("a"));
		m.insert(QChar(u's'), QStringLiteral("s"));
		m.insert(QChar(u'r'), QStringLiteral("r"));
		m.insert(QChar(u'?'), QStringLiteral("v"));
		m.insert(QChar(u'?'), QStringLiteral("a"));
		m.insert(QChar(u'?'), QStringLiteral("c"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'?'), QStringLiteral("m"));
		m.insert(QChar(u'?'), QStringLiteral("w"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'c'), QStringLiteral("c"));
		m.insert(QChar(u'?'), QStringLiteral("g"));
		m.insert(QChar(u'c'), QStringLiteral("c"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("k"));
		m.insert(QChar(u'?'), QStringLiteral("q"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("s"));
		m.insert(QChar(u'?'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("h"));
		m.insert(QChar(u'o'), QStringLiteral("o"));
		m.insert(QChar(u'?'), QStringLiteral("tz"));
		m.insert(QChar(u'?'), QStringLiteral("e"));
		m.insert(QChar(u'і'), QStringLiteral("i"));
		m.insert(QChar(u'ї'), QStringLiteral("i"));
		return m;
	}();

	static const QHash<QChar, QString> ruMap = []
	{
		QHash<QChar, QString> m;
		m.reserve(33);
		m.insert(QChar(u'а'), QStringLiteral("a"));
		m.insert(QChar(u'б'), QStringLiteral("b"));
		m.insert(QChar(u'в'), QStringLiteral("v"));
		m.insert(QChar(u'г'), QStringLiteral("g"));
		m.insert(QChar(u'д'), QStringLiteral("d"));
		m.insert(QChar(u'е'), QStringLiteral("e"));
		m.insert(QChar(u'ё'), QStringLiteral("yo"));
		m.insert(QChar(u'ж'), QStringLiteral("zh"));
		m.insert(QChar(u'з'), QStringLiteral("z"));
		m.insert(QChar(u'и'), QStringLiteral("i"));
		m.insert(QChar(u'й'), QStringLiteral("i"));
		m.insert(QChar(u'к'), QStringLiteral("k"));
		m.insert(QChar(u'л'), QStringLiteral("l"));
		m.insert(QChar(u'м'), QStringLiteral("m"));
		m.insert(QChar(u'н'), QStringLiteral("n"));
		m.insert(QChar(u'о'), QStringLiteral("o"));
		m.insert(QChar(u'п'), QStringLiteral("p"));
		m.insert(QChar(u'р'), QStringLiteral("r"));
		m.insert(QChar(u'с'), QStringLiteral("s"));
		m.insert(QChar(u'т'), QStringLiteral("t"));
		m.insert(QChar(u'у'), QStringLiteral("u"));
		m.insert(QChar(u'ф'), QStringLiteral("f"));
		m.insert(QChar(u'х'), QStringLiteral("h"));
		m.insert(QChar(u'ц'), QStringLiteral("ts"));
		m.insert(QChar(u'ч'), QStringLiteral("ch"));
		m.insert(QChar(u'ш'), QStringLiteral("sh"));
		m.insert(QChar(u'щ'), QStringLiteral("sch"));
		m.insert(QChar(u'ы'), QStringLiteral("i"));
		m.insert(QChar(u'ь'), QStringLiteral(""));
		m.insert(QChar(u'ъ'), QStringLiteral(""));
		m.insert(QChar(u'э'), QStringLiteral("e"));
		m.insert(QChar(u'ю'), QStringLiteral("yu"));
		m.insert(QChar(u'я'), QStringLiteral("ya"));
		return m;
	}();

	if (s.isEmpty()) {
		return s;
	}

	QString out;
	out.reserve(s.size() * 2);

	for (int i = 0; i < s.size();) {
		const QChar ch = s.at(i++);
		if (const auto tg = trMap.constFind(ch); tg != trMap.cend()) {
			out += tg.value();
			continue;
		}
		if (const auto tr = ruMap.constFind(ch); tr != ruMap.cend()) {
			out += tr.value();
			continue;
		}
		out += ch;
	}

	return out;
}

QString normalized(const QString &s) {
	auto lower = s.trimmed().toLower();
	return translitSafe(lower);
}

bool hasCommonArtist(const QStringList &baseArtists, const QString &itunesArtists) {
	if (itunesArtists.trimmed().isEmpty()) return false;
	static const QRegularExpression splitter(QString::fromUtf8(R"((?i)\s*(?:,|&|feat\.?|ft\.?)\s*)"));
	const auto itunesList = QString(itunesArtists)
		.split(splitter, Qt::SkipEmptyParts)
		.replaceInStrings(QRegularExpression("^\\s+|\\s+$"), QString());
	for (const auto &base : baseArtists) {
		const auto b = normalized(base);
		for (const auto &it : itunesList) {
			const auto i = normalized(it);
			if (i == b) return true;
		}
	}
	return false;
}

QStringList splitArtists(const QString &artists) {
	static const QRegularExpression splitter(QString::fromUtf8(R"((?i)\s*(?:,|&|feat\.?|ft\.?)\s*)"));
	auto list = artists.split(splitter, Qt::SkipEmptyParts);
	for (auto &e : list) e = e.trimmed();
	return list;
}

std::unique_ptr<QNetworkReply, void(*)(QNetworkReply *)> execWithTimeout(
	QNetworkAccessManager &nam,
	const QNetworkRequest &req,
	int timeoutMs) {
	QNetworkReply *reply = nam.get(req);
	QEventLoop loop;
	QTimer timer;
	timer.setSingleShot(true);
	QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
	QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
	timer.start(timeoutMs);
	loop.exec();
	if (timer.isActive()) {
		timer.stop();
	} else {
		reply->abort();
	}
	return {reply, [](QNetworkReply *r) { if (r) r->deleteLater(); }};
}

QByteArray getBytesWithTimeout(const QUrl &url, int timeoutMs, QByteArray *contentTypeOut = nullptr) {
	QNetworkAccessManager nam;
	QNetworkRequest req(url);
	req.setAttribute(QNetworkRequest::RedirectPolicyAttribute, QNetworkRequest::NoLessSafeRedirectPolicy);
	auto replyPtr = execWithTimeout(nam, req, timeoutMs);
	QNetworkReply *reply = replyPtr.get();
	if (!reply) return {};
	if (reply->error() != QNetworkReply::NoError) return {};
	if (contentTypeOut) {
		*contentTypeOut = reply->header(QNetworkRequest::ContentTypeHeader).toByteArray();
	}
	return reply->readAll();
}

struct ItunesTrack
{
	QString trackName;
	QString artistName;
	QString collectionName;
	QString artworkUrl100;
};

QList<ItunesTrack> parseTracks(const QByteArray &json) {
	QList<ItunesTrack> out;
	auto doc = QJsonDocument::fromJson(json);
	if (!doc.isObject()) return out;
	auto root = doc.object();
	auto results = root.value(QString::fromUtf8("results")).toArray();
	out.reserve(results.size());
	for (const auto &v : results) {
		const auto o = v.toObject();
		ItunesTrack t;
		t.trackName = o.value(QString::fromUtf8("trackName")).toString();
		t.artistName = o.value(QString::fromUtf8("artistName")).toString();
		t.collectionName = o.value(QString::fromUtf8("collectionName")).toString();
		t.artworkUrl100 = o.value(QString::fromUtf8("artworkUrl100")).toString();
		out.push_back(t);

		LOG(("parsed track: %1 - %2 [%3] (art: %4 )").arg(t.artistName, t.trackName, t.collectionName, t.artworkUrl100));
	}
	return out;
}

QString pickArtworkUrl(const QList<ItunesTrack> &tracks,
					   const QString &targetTitle,
					   const QStringList &baseArtists) {
	if (tracks.isEmpty()) return {};
	for (const auto &t : tracks) {
		if (!t.trackName.compare(targetTitle, Qt::CaseInsensitive) && hasCommonArtist(baseArtists, t.artistName)) {
			return t.artworkUrl100;
		}
	}
	return tracks.first().artworkUrl100;
}

QUrl buildItunesUrl(const QString &performer, const QString &title) {
	QUrl url(QString::fromUtf8("https://itunes.apple.com/search"));
	QUrlQuery query;
	query.addQueryItem(QString::fromUtf8("term"), title + QString::fromUtf8(" - ") + performer);
	query.addQueryItem(QString::fromUtf8("entity"), QString::fromUtf8("song"));
	query.addQueryItem(QString::fromUtf8("limit"), QString::fromUtf8("5"));
	url.setQuery(query);
	return url;
}

QString upgradeArtworkSize(QString url, int sizeHint) {
	if (url.isEmpty()) return url;
	url.replace(QString::fromUtf8("100x100"),
				(sizeHint >= 600) ? QString::fromUtf8("600x600") : QString::fromUtf8("300x300"));
	return url;
}

} // namespace

QPixmap FetchCover(const QString &performer, const QString &title, int sizeHintPx, int timeoutMs) {
	const auto perf = performer.trimmed();
	const auto titl = title.trimmed();
	if (perf.isEmpty() && titl.isEmpty()) return {};

	const auto key = perf + QString::fromUtf8(" - ") + titl;
	if (auto *entry = cache().object(key)) {
		return entry->pix;
	}

	const auto url = buildItunesUrl(perf, titl);
	const auto json = getBytesWithTimeout(url, timeoutMs);
	if (json.isEmpty()) return {};
	const auto tracks = parseTracks(json);
	if (tracks.isEmpty()) return {};

	const auto baseArtists = splitArtists(perf);
	auto artwork = pickArtworkUrl(tracks, titl, baseArtists);
	artwork = upgradeArtworkSize(std::move(artwork), sizeHintPx);
	if (artwork.isEmpty()) return {};

	QByteArray contentType;
	const auto imgBytes = getBytesWithTimeout(QUrl(artwork), timeoutMs, &contentType);
	if (imgBytes.isEmpty()) return {};

	QImage img;
	if (!img.loadFromData(imgBytes)) return {};
	QPixmap pix = QPixmap::fromImage(img);

	auto *stored = new CacheEntry{pix};
	cache().insert(key, stored);
	return pix;
}

}

