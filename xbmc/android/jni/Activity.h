#pragma once
/*
 *      Copyright (C) 2014 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "JNIBase.h"
#include "Context.h"

struct ANativeActivity;

class CJNIActivity : public CJNIContext
{
public:
  CJNIActivity(const ANativeActivity *nativeActivity);
  ~CJNIActivity();

  static bool moveTaskToBack(bool nonRoot);

private:
  CJNIActivity();
};

///////////////////////////////////

class CJNIXbmcMainActivity : public CJNIActivity
{
public:
  CJNIXbmcMainActivity(const ANativeActivity *nativeActivity);
  ~CJNIXbmcMainActivity();

  static CJNIXbmcMainActivity* GetAppInstance() { return m_appInstance; }

  static void _onNewIntent(JNIEnv *env, jobject context, jobject intent);

private:
  static CJNIXbmcMainActivity *m_appInstance;

protected:
  virtual void onNewIntent(CJNIIntent intent)=0;
};

