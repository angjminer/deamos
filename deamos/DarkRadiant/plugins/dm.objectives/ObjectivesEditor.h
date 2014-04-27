#ifndef OBJECTIVESEDITOR_H_
#define OBJECTIVESEDITOR_H_

#include "Objective.h"
#include "ObjectiveEntity.h"

#include "icommandsystem.h"
#include "gtkutil/WindowPosition.h"
#include "gtkutil/window/BlockingTransientWindow.h"
#include "gtkutil/GladeWidgetHolder.h"

#include "ObjectiveEntityFinder.h"

#include <map>
#include <string>
#include <gtkmm/liststore.h>

namespace Gtk
{
	class VBox;
	class HBox;
	class TreeView;
	class Button;
}

/* FORWARD DECLS */
class Entity;

namespace objectives
{

/**
 * Dialog for adding and manipulating mission objectives in Dark Mod missions.
 */
class ObjectivesEditor :
	public gtkutil::BlockingTransientWindow,
    private gtkutil::GladeWidgetHolder
{
private:
	// List of target_addobjectives entities
	ObjectiveEntityListColumns _objEntityColumns;
	Glib::RefPtr<Gtk::ListStore> _objectiveEntityList;

	// List of actual objectives associated with the selected entity
	ObjectivesListColumns _objectiveColumns;
	Glib::RefPtr<Gtk::ListStore> _objectiveList;
	
	// Pointer to the worldspawn entity
	Entity* _worldSpawn;

	// Map of ObjectiveEntity objectives, indexed by the name of the world
	// entity
	ObjectiveEntityMap _entities;

	// Iterators for current entity and current objective
	ObjectiveEntityMap::iterator _curEntity;
	Gtk::TreeModel::iterator _curObjective;

	// The position/size memoriser
	gtkutil::WindowPosition _windowPosition;

	// The list of objective eclasses (defined in the registry)
	std::vector<std::string> _objectiveEClasses;

private:

	// Constructor creates widgets
	ObjectivesEditor();

	// Widget construction helpers
	void setupEntitiesPanel();
	void setupObjectivesPanel();
	Gtk::Widget& createObjectiveEditPanel();
	Gtk::Widget& createLogicPanel();
	Gtk::Widget& createButtons();

	// gtkmm callbacks
	void _onCancel();
	void _onOK();
	void _onStartActiveCellToggled(const Glib::ustring& path);
	void _onEntitySelectionChanged();
	void _onObjectiveSelectionChanged();
	void _onAddEntity();
	void _onDeleteEntity();
	void _onAddObjective();
	void _onEditObjective();
	void _onMoveUpObjective();
	void _onMoveDownObjective();
	void _onDeleteObjective();
	void _onClearObjectives();
	void _onEditLogic();
	void _onEditObjConditions();

	// Populate the dialog widgets with appropriate state from the map
	void populateWidgets();
	void populateActiveAtStart();

	// Refresh the objectives list from the currently-selected ObjectiveEntity
	void refreshObjectivesList();

	// Return the currently-selected objective
	Objective& getCurrentObjective();

	// Clears the internal containers
	void clear();

	virtual void _preHide();
	virtual void _preShow();

public:

	/**
	 * Static method to display the Objectives Editor dialog.
	 */
	static void displayDialog(const cmd::ArgumentList& args);
};

}

#endif /*OBJECTIVESEDITOR_H_*/
