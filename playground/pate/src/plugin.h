// This file is part of Pate, Kate' Python scripting plugin.
//
// Copyright (C) 2006 Paul Giannaros <paul@giannaros.org>
// Copyright (C) 2012 Shaheed Haque <srhaque@theiet.org>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) version 3.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public License
// along with this library; see the file COPYING.LIB.  If not, write to
// the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
// Boston, MA 02110-1301, USA.

#ifndef PATE_PLUGIN_H
#define PATE_PLUGIN_H

#include <kate/mainwindow.h>
#include <kate/plugin.h>
#include <kate/pluginconfigpageinterface.h>

#include <kxmlguiclient.h>

#include "Python.h"
class QPushButton;
//class QCheckBox;
class QTreeView;

namespace Pate
{

/**
 * The Pate plugin itself.
 */
class Plugin :
    public Kate::Plugin,
    public Kate::PluginConfigPageInterface
{
    Q_OBJECT
    Q_INTERFACES(Kate::PluginConfigPageInterface)

public:
    explicit Plugin(QObject *parent = 0, const QStringList& = QStringList());
    virtual ~Plugin();
    
    Kate::PluginView *createView(Kate::MainWindow *mainWindow);

    /**
     * Read the config for the plugin.
     */
    void readConfig(class ConfigPage *page);

    /**
     * Read the config for the plugin.
     */
    void writeConfig(class ConfigPage *page);

    // PluginConfigPageInterface
    uint configPages() const { return 1; };
    Kate::PluginConfigPage *configPage(uint number = 0, QWidget *parent = 0, const char *name = 0);
    QString configPageName(uint number = 0) const;
    QString configPageFullName(uint number = 0) const;
    KIcon configPageIcon(uint number = 0) const;    
};

/**
 * The Pate plugin view.
 */
class PluginView :
    public Kate::PluginView
{
    Q_OBJECT

public:
    PluginView(Kate::MainWindow *window);
};

/**
 * The Pate plugin's configuration view.
 */
class ConfigPage :
    public Kate::PluginConfigPage
{
    Q_OBJECT

public:
    explicit ConfigPage(QWidget *parent = 0, Plugin *plugin = 0);
    virtual ~ConfigPage() {}

    virtual void apply();
    virtual void reset();
    virtual void defaults() {}

private:
    friend class Plugin;
    Plugin *m_plugin;
    QTreeView *m_tree;
    QPushButton *m_reload;
    //QCheckBox *cbAutoSyncronize;
    //QCheckBox *cbSetEditor;
};

} // namespace Pate

#endif
