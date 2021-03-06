#pragma once

#include "itextstream.h"
#include "ifilesystem.h"
#include "iimage.h"
#include <iostream>

ImagePtr LoadDDS(ArchiveFile& file);

/* greebo: A DDSLoader is capable of loading DDS image files.
 *
 * Use load() to actually retrieve an Image* object with the loaded image.
 *
 * Shouldn't be used to load textures directly, use the
 * GlobalMaterialManager() module instead.
 *
 * Complies with the ImageLoader interface defined in "iimage.h"
 */
class DDSLoader :
	public ImageLoader
{
public:
	/* greebo: This loads the file and returns the pointer to
	 * the allocated Image object (or an empty pointer, if the load failed).
	 */
	ImagePtr load(ArchiveFile& file) const {
		// Pass the call to the according load function
		return LoadDDS(file);
	}

	/* greebo: Gets the file extension of the supported image file type (e.g. "dds")
	 */
	std::string getExtension() const {
		return "dds";
	}

	/* greebo: Returns the prefix that is necessary to construct the
	 * path to the dds files.
	 */
	std::string getPrefix() const {
		return "dds/";
	}

	// RegisterableModule implementation
	virtual const std::string& getName() const {
		static std::string _name("ImageLoaderDDS");
		return _name;
	}

	virtual const StringSet& getDependencies() const {
		static StringSet _dependencies; // no dependencies
		return _dependencies;
	}

	virtual void initialiseModule(const ApplicationContext& ctx) {
		rMessage() << "ImageLoaderDDS::initialiseModule called.\n";
	}
};
