/*
 * Copyright (C) 2006 Apple Computer, Inc.
 * Copyright (C) 2009 Torch Mobile Inc. http://www.torchmobile.com/
 * Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef WEEX_UIKIT_CORE_RENDERING_HITTESTREQUEST_H_
#define WEEX_UIKIT_CORE_RENDERING_HITTESTREQUEST_H_

namespace blink {

class HitTestRequest {
 public:
  enum RequestType {
    ReadOnly = 1 << 1,
    Active = 1 << 2,
    Move = 1 << 3,
    Release = 1 << 4,
    IgnoreClipping = 1 << 5,
    SVGClipContent = 1 << 6,
    IgnorePointerEventsNone = 1 << 8,
  };

  typedef unsigned HitTestRequestType;

  HitTestRequest(HitTestRequestType requestType, int event) : m_requestType(requestType), m_requestEvent(event) {

  }

  bool readOnly() const { return m_requestType & ReadOnly; }
  bool active() const { return m_requestType & Active; }
  bool move() const { return m_requestType & Move; }
  bool release() const { return m_requestType & Release; }
  bool ignoreClipping() const { return m_requestType & IgnoreClipping; }
  bool svgClipContent() const { return m_requestType & SVGClipContent; }
  bool ignorePointerEventsNone() const {
    return m_requestType & IgnorePointerEventsNone;
  }

  HitTestRequestType type() const {
    return m_requestType;
  }

  int requestEvent()const {
    return m_requestEvent;
  }

 private:
  HitTestRequestType m_requestType;
  int m_requestEvent;
};

}  // namespace blink

#endif  // WEEX_UIKIT_CORE_RENDERING_HITTESTREQUEST_H_
