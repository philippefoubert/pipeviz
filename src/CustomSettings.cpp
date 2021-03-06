#include "CustomSettings.h"

#include <QSettings>

#define COMPANY_NAME              "virinext"
#define APPLICATION_NAME          "pipeviz"

void
CustomSettings::saveLastIODirectory (const QString &name)
{
  QSettings settings (COMPANY_NAME, APPLICATION_NAME);
  settings.setValue ("last_directory", name);
}

QString
CustomSettings::lastIODirectory ()
{
  QSettings settings (COMPANY_NAME, APPLICATION_NAME);
  QString res = settings.value ("last_directory").toString ();

  if (res.isEmpty ())
    res = "./";

  return res;
}

void
CustomSettings::saveFavoriteList (const QStringList &favorite_list)
{
  QSettings settings (COMPANY_NAME, APPLICATION_NAME);
  settings.setValue("favorite_list", QVariant::fromValue(favorite_list));
}

QStringList
CustomSettings::loadFavoriteList ()
{
  QSettings settings (COMPANY_NAME, APPLICATION_NAME);
  QStringList data = settings.value("favorite_list").value<QStringList>();

  return data;
}

void
CustomSettings::saveMainWindowGeometry (const QByteArray &geometry)
{
  QSettings settings (COMPANY_NAME, APPLICATION_NAME);
  settings.setValue ("geometry", geometry);
}

QByteArray
CustomSettings::mainWindowGeometry ()
{
  QSettings settings (COMPANY_NAME, APPLICATION_NAME);
  return settings.value ("geometry").toByteArray ();
}

void
CustomSettings::saveGstDebugString (const QString &string)
{
  QSettings settings (COMPANY_NAME, APPLICATION_NAME);
  settings.setValue ("gst_log_string", string);
}

QString
CustomSettings::lastGstDebugString ()
{
  QSettings settings (COMPANY_NAME, APPLICATION_NAME);
  QString res = settings.value ("gst_log_string").toString ();

  if (res.isEmpty ())
    res = "GST_DEBUG=*:5";

  return res;
}
