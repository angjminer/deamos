#ifndef TARGETLIST_H_
#define TARGETLIST_H_

#include "ientity.h"

#include <set>
#include <string>
#include <boost/algorithm/string/predicate.hpp>

namespace objectives
{

/**
 * A list of entities targeted from a given source entity. During construction,
 * this class builds a set of target entities by enumerating the "target<x>"
 * keys on the source entity. It then provides a method to check whether a given
 * entity is targeted by the source entity.
 */
class TargetList
: public Entity::Visitor
{
	// Source entity
	const Entity* _src;

	// The set of targeted entities, by name
	typedef std::set<std::string> StringSet;
	StringSet _set;

public:

	/**
	 * Construct a TargetList with the given source entity. The source entity
	 * is immediately scanned for <b>target</b> keyvalues that refer to other
	 * entities.
	 *
	 * @param src
	 * The source Entity to query for targets.
	 */
	TargetList(const Entity* src)
	: _src(src)
	{
		assert(src);
		_src->forEachKeyValue(*this);
	}

	/**
	 * @see Entity::Visitor::visit()
	 */
	void visit(const std::string& key, const std::string& value) {
		// If the key starts with "target", add the value to the set
		if (boost::algorithm::istarts_with(key, "target"))
			_set.insert(value);
	}

	/**
	 * Query whether the supplied entity is targeted by the source entity.
	 *
	 * @param qtarget
	 * The destination entity.
	 *
	 * @return
	 * true if the destination Entity appears in the list of targets for the
	 * source Entity, false otherwise.
	 */
	bool isTargeted(const Entity* qtarget) const {

		assert(qtarget);

		// Check if the queried entity's name is in the set
		if (_set.find(qtarget->getKeyValue("name")) != _set.end())
			return true;
		else
			return false;
	}
};

} // namespace objectives

#endif /*TARGETLIST_H_*/
