/*
 * Copyright (C) 2012-2016 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef _GAZEBO_RENDERING_OSVR_CAMERA_PRIVATE_HH_
#define _GAZEBO_RENDERING_OSVR_CAMERA_PRIVATE_HH_

#include "osvr/ClientKit/ClientKit.h"
#include "gazebo/util/system.hh"

namespace Ogre
{
  class Camera;
  class Viewport;
  class SceneManager;
}

namespace gazebo
{
  namespace rendering
  {
    /// \brief Private data for the OSVR Camera class
    class GZ_RENDERING_VISIBLE OSVRCameraPrivate
    {
      /// \brief Constructor
      public: OSVRCameraPrivate()
              : rightCamera(NULL),
                externalCamera(NULL),
                rightViewport(NULL),
                externalViewport(NULL),
                externalSceneManager(NULL),
                osvrContext(NULL),
                node(NULL),
                controlSub(NULL),
                ready(false),
                frameIndex(1),
                osvrTrackingWarned(false) {}

      /// \brief Ogre camera for the right OSVR screen.
      public: Ogre::Camera *rightCamera;

      /// \brief Camera in the external scene that render the distortion
      /// meshes.
      public: Ogre::Camera *externalCamera;

      /// \brief View port for the right camera.
      public: Ogre::Viewport *rightViewport;

      /// \brief View port for the external camera.
      public: Ogre::Viewport *externalViewport;

      /// \brief External scene manager. This holds the distortion meshes
      /// and the external camera.
      public: Ogre::SceneManager *externalSceneManager;

      /// \brief OSVR library context.
      public: osvr::clientkit::ClientContext *osvrContext;

      /// \brief OSVR interface to receive tracking data
      public: osvr::clientkit::Interface osvrInterface;

      /// \brief Transport node for using gazebo pub/sub.
      public: transport::NodePtr node;

      /// \brief Subscriber used to receive updates on world_control topic.
      public: transport::SubscriberPtr controlSub;

      /// \brief True when OSVR is connected and ready to use.
      public: bool ready;

      /// \brief Right camera render texture.
      public: Ogre::TexturePtr renderTextureRight;

      /// \brief Left camera render texture.
      public: Ogre::TexturePtr renderTextureLeft;

      /// \brief Frame index used for OSVR timing
      public: unsigned int frameIndex;

      /// \brief Flag used to prevent multiple messages from being
      /// displayed.
      public: bool osvrTrackingWarned;
    };
  }
}
#endif
