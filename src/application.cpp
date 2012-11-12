/*
 * application.cpp
 * Copyright 2012 Scott MacDonald
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "application.h"
#include "utils.h"
#include "resourcesloader.h"
#include "renderer.h"

#include <cassert>

/**
 * Constructor
 */
Application::Application()
    : mpResourcesLoader( NULL ),
      mpRenderer( NULL )
{
}

/**
 * Destructor
 */
Application::~Application()
{
    // Do not delete the management subsystems, they will be deleted by the
    // active gameapp instance
}

/**
 * Return the active application instance as a reference
 */
Application& Application::instance()
{
    static Application app;
    return app;
}

/**
 * Return the active resources loader as a reference
 */
ResourcesLoader& Application::resources()
{
    // Grab the current instance
    Application& app = instance();

    // Make sure the loader is created and set
    assert( app.mpResourcesLoader != NULL && "Must create resources loader before accessing" );

    if ( app.mpResourcesLoader == NULL )
    {
        raiseError( "Did not create resources loader prior to using it", EERROR_APP );
    }

    // This is going to fail horribly if we get this far and there's no valid
    // pointer
    return *app.mpResourcesLoader;
}

/**
 * Return the active renderer as a reference
 */
Renderer& Application::renderer()
{
    // Grab the current instance
    Application& app = instance();

    // Make sure the renderer is created and set
    assert( app.mpRenderer != NULL && "Must create renderer before accessing" );

    if ( app.mpRenderer == NULL )
    {
        raiseError( "Did not create renderer prior to using it", EERROR_APP );
    }

    // This is going to fail horribly if we get this far and there's no valid
    // pointer
    return *app.mpRenderer;
}

/**
 * Sets the resources loader
 */
void Application::setResourcesLoader( ResourcesLoader * pResourcesLoader )
{
    Delete( mpResourcesLoader );
    mpResourcesLoader = pResourcesLoader;
}

/**
 * Sets the renderer
 */
void Application::setRenderer( Renderer * pRenderer )
{
    Delete( mpRenderer );
    mpRenderer = pRenderer;
}