#pragma once

#include "icommandsystem.h"

namespace selection
{

namespace clipboard
{

/**
 * De-selects everything and pastes the clipboard contents to the global map
 */
void pasteToMap();

/**
 * Either copies the current map selection to the clipboard (in map format)
 * or (when faces are selected component-wise) copies the current shader 
 * from selected faces.
 */
void copy(const cmd::ArgumentList& args);

/**
 * Either pastes the clipboard contents to the current map 
 * or (when faces are selected component-wise) applies the previously
 * copied shader to the selected faces.
 */
void paste(const cmd::ArgumentList& args);

/**
 * Pastes the clipboard contents to the position the camera is roughly looking at.
 */
void pasteToCamera(const cmd::ArgumentList& args);

} // namespace

} // namespace
