/*
 * Copyright (C) by Michael Schuster <michael@nextcloud.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#ifndef FLOW2AUTHWIDGET_H
#define FLOW2AUTHWIDGET_H

#include <QUrl>
#include <QWidget>

#include "creds/flow2auth.h"

#include "ui_flow2authwidget.h"

namespace OCC {

class Flow2AuthWidget : public QWidget
{
    Q_OBJECT
public:
    Flow2AuthWidget(Account *account, QWidget *parent = nullptr);
    virtual ~Flow2AuthWidget();

    void setError(const QString &error);

public Q_SLOTS:
    void asyncAuthResult(Flow2Auth::Result, const QString &user, const QString &appPassword);

signals:
    void urlCatched(const QString user, const QString pass, const QString host);

private:
    Account *_account;
    QString _user;
    QString _appPassword;
    QScopedPointer<Flow2Auth> _asyncAuth;
    Ui_Flow2AuthWidget _ui;
};

}

#endif // FLOW2AUTHWIDGET_H
