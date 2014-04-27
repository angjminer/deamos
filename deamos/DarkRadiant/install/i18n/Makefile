# Makefile for PO directory in any package using GNU gettext.
# Copyright (C) 1995-1997, 2000-2007, 2009-2010 by Ulrich Drepper <drepper@gnu.ai.mit.edu>
#
# This file can be copied and used freely without restrictions.  It can
# be used in projects which are not available under the GNU General Public
# License but which still want to provide support for the GNU gettext
# functionality.
# Please note that the actual code of GNU gettext is covered by the GNU
# General Public License and is *not* in the public domain.
#
# Origin: gettext-0.18
GETTEXT_MACRO_VERSION = 0.18

PACKAGE = darkradiant
VERSION = 1.8.0
PACKAGE_BUGREPORT = 

SHELL = /bin/sh


srcdir = .
top_srcdir = ../..


prefix = /usr/local
exec_prefix = ${prefix}
datarootdir = ${prefix}/share
datadir = ${datarootdir}
localedir = ${datarootdir}/locale
gettextsrcdir = $(datadir)/gettext/po

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644

# We use $(mkdir_p).
# In automake <= 1.9.x, $(mkdir_p) is defined either as "mkdir -p --" or as
# "$(mkinstalldirs)" or as "$(install_sh) -d". For these automake versions,
# ${SHELL} /home/angelo/gameprojects/dhewmd3src/darkradiant/DarkRadiant/install-sh does not start with $(SHELL), so we add it.
# In automake >= 1.10, /bin/mkdir -p is derived from ${MKDIR_P}, which is defined
# either as "/path/to/mkdir -p" or ".../install-sh -c -d". For these automake
# versions, $(mkinstalldirs) and $(install_sh) are unused.
mkinstalldirs = $(SHELL) ${SHELL} /home/angelo/gameprojects/dhewmd3src/darkradiant/DarkRadiant/install-sh -d
install_sh = $(SHELL) ${SHELL} /home/angelo/gameprojects/dhewmd3src/darkradiant/DarkRadiant/install-sh
MKDIR_P = /bin/mkdir -p
mkdir_p = /bin/mkdir -p

GMSGFMT_ = /usr/bin/msgfmt
GMSGFMT_no = /usr/bin/msgfmt
GMSGFMT_yes = /usr/bin/msgfmt
GMSGFMT = $(GMSGFMT_$(USE_MSGCTXT))
MSGFMT_ = /usr/bin/msgfmt
MSGFMT_no = /usr/bin/msgfmt
MSGFMT_yes = /usr/bin/msgfmt
MSGFMT = $(MSGFMT_$(USE_MSGCTXT))
XGETTEXT_ = /usr/bin/xgettext
XGETTEXT_no = /usr/bin/xgettext
XGETTEXT_yes = /usr/bin/xgettext
XGETTEXT = $(XGETTEXT_$(USE_MSGCTXT))
MSGMERGE = msgmerge
MSGMERGE_UPDATE = /usr/bin/msgmerge --update
MSGINIT = msginit
MSGCONV = msgconv
MSGFILTER = msgfilter

POFILES =  de.po
GMOFILES =  de.gmo
UPDATEPOFILES =  de.po-update
DUMMYPOFILES =  de.nop
DISTFILES.common = Makefile.in.in \
$(DISTFILES.common.extra1) $(DISTFILES.common.extra2) $(DISTFILES.common.extra3)
DISTFILES = $(DISTFILES.common) Makevars POTFILES.in \
$(POFILES) $(GMOFILES) \
$(DISTFILES.extra1) $(DISTFILES.extra2) $(DISTFILES.extra3)

POTFILES = \
     ../../radiant/textool/TexTool.cpp \
     ../../radiant/settings/GameManager.cpp \
     ../../radiant/settings/LanguageManager.cpp \
     ../../radiant/modulesystem/ModuleRegistry.cpp \
     ../../radiant/brushmanip.cpp \
     ../../radiant/patchmanip.cpp \
     ../../radiant/selection/shaderclipboard/ShaderClipboard.cpp \
     ../../radiant/selection/algorithm/Shader.cpp \
     ../../radiant/selection/algorithm/Curves.cpp \
     ../../radiant/selection/algorithm/Entity.cpp \
     ../../radiant/selection/algorithm/Group.cpp \
     ../../radiant/selection/algorithm/Primitives.cpp \
     ../../radiant/selection/algorithm/Transformation.cpp \
     ../../radiant/selection/selectionset/SelectionSetToolmenu.cpp \
     ../../radiant/clipper/Clipper.cpp \
     ../../radiant/entity.cpp \
     ../../radiant/mainframe_old.cpp \
     ../../radiant/layers/LayerSystem.cpp \
     ../../radiant/map/FindMapElements.cpp \
     ../../radiant/map/MapResource.cpp \
     ../../radiant/map/CounterManager.cpp \
     ../../radiant/map/RegionManager.cpp \
     ../../radiant/map/PointFile.cpp \
     ../../radiant/map/AutoSaver.cpp \
     ../../radiant/map/MapFileChooserPreview.cpp \
     ../../radiant/map/Map.cpp \
     ../../radiant/camera/CameraSettings.cpp \
     ../../radiant/camera/FloatingCamWnd.cpp \
     ../../radiant/xyview/GlobalXYWnd.cpp \
     ../../radiant/xyview/XYWnd.cpp \
     ../../radiant/referencecache/ModelCache.cpp \
     ../../radiant/ui/about/AboutDialog.cpp \
     ../../radiant/ui/overlay/OverlayDialog.cpp \
     ../../radiant/ui/mru/MRU.cpp \
     ../../radiant/ui/ortho/OrthoContextMenu.cpp \
     ../../radiant/ui/common/ShaderChooser.cpp \
     ../../radiant/ui/common/EntityChooser.cpp \
     ../../radiant/ui/common/SoundShaderPreview.cpp \
     ../../radiant/ui/common/TexturePreviewCombo.cpp \
     ../../radiant/ui/common/SoundChooser.cpp \
     ../../radiant/ui/common/CommandEntry.cpp \
     ../../radiant/ui/common/ShaderSelector.cpp \
     ../../radiant/ui/common/ShaderDefinitionView.cpp \
     ../../radiant/ui/commandlist/ShortcutChooser.cpp \
     ../../radiant/ui/commandlist/CommandList.cpp \
     ../../radiant/ui/einspector/SoundPropertyEditor.cpp \
     ../../radiant/ui/einspector/ClassnamePropertyEditor.cpp \
     ../../radiant/ui/einspector/AddPropertyDialog.cpp \
     ../../radiant/ui/einspector/ModelPropertyEditor.cpp \
     ../../radiant/ui/einspector/SkinChooser.cpp \
     ../../radiant/ui/einspector/TexturePropertyEditor.cpp \
     ../../radiant/ui/einspector/EntityPropertyEditor.cpp \
     ../../radiant/ui/einspector/Vector3PropertyEditor.cpp \
     ../../radiant/ui/einspector/EntityInspector.cpp \
     ../../radiant/ui/einspector/SkinPropertyEditor.cpp \
     ../../radiant/ui/einspector/LightTextureChooser.cpp \
     ../../radiant/ui/mapinfo/ShaderInfoTab.cpp \
     ../../radiant/ui/mapinfo/MapInfoDialog.cpp \
     ../../radiant/ui/mapinfo/EntityInfoTab.cpp \
     ../../radiant/ui/mapinfo/ModelInfoTab.cpp \
     ../../radiant/ui/mainframe/EmbeddedLayout.cpp \
     ../../radiant/ui/mainframe/SplitPaneLayout.cpp \
     ../../radiant/ui/mainframe/LayoutCommand.h \
     ../../radiant/ui/mainframe/FloatingLayout.cpp \
     ../../radiant/ui/mainframe/MainFrame.cpp \
     ../../radiant/ui/entitychooser/EntityClassChooser.cpp \
     ../../radiant/ui/menu/FiltersMenu.cpp \
     ../../radiant/ui/prefdialog/PrefDialog.cpp \
     ../../radiant/ui/lightinspector/LightInspector.cpp \
     ../../radiant/ui/findshader/FindShader.cpp \
     ../../radiant/ui/particles/ParticlesChooser.cpp \
     ../../radiant/ui/layers/LayerControl.cpp \
     ../../radiant/ui/layers/LayerControlDialog.cpp \
     ../../radiant/ui/mediabrowser/MediaBrowser.cpp \
     ../../radiant/ui/mediabrowser/TextureDirectoryLoader.h \
     ../../radiant/ui/texturebrowser/TextureBrowser.cpp \
     ../../radiant/ui/surfaceinspector/SurfaceInspector.cpp \
     ../../radiant/ui/modelselector/ModelSelector.cpp \
     ../../radiant/ui/modelselector/ModelFileFunctor.h \
     ../../radiant/ui/brush/QuerySidesDialog.cpp \
     ../../radiant/ui/transform/TransformDialog.cpp \
     ../../radiant/ui/patch/PatchThickenDialog.cpp \
     ../../radiant/ui/patch/BulgePatchDialog.cpp \
     ../../radiant/ui/patch/PatchInspector.cpp \
     ../../radiant/ui/patch/PatchCreateDialog.cpp \
     ../../radiant/ui/patch/CapDialog.cpp \
     ../../radiant/ui/filterdialog/FilterEditor.cpp \
     ../../radiant/ui/filterdialog/FilterDialog.cpp \
     ../../radiant/main.cpp \
     ../../radiant/brush/BrushModule.cpp \
     ../../radiant/brush/csg/CSG.cpp \
     ../../radiant/patch/PatchCreators.h \
     ../../radiant/patch/Patch.cpp \
     ../../include/i18n.h \
     ../../libs/gtkutil/ModalProgressDialog.cpp \
     ../../libs/gtkutil/IConv.h \
     ../../libs/gtkutil/FileChooser.cpp \
     ../../libs/gtkutil/dialog/MessageBox.cpp \
     ../../libs/gtkutil/ConsoleView.cpp \
     ../../libs/gtkutil/PathEntry.cpp \
     ../../libs/pivot.h \
     ../../libs/radiant_jpeglib.h \
     ../../libs/picomodel/pm_lwo.c \
     ../../libs/picomodel/lwo/lwo2.h \
     ../../libs/picomodel/lwo/lwob.c \
     ../../plugins/eclasstree/plugin.cpp \
     ../../plugins/eclasstree/EClassTree.cpp \
     ../../plugins/entity/EntityCreator.cpp \
     ../../plugins/dm.conversation/plugin.cpp \
     ../../plugins/dm.conversation/ConversationEntityFinder.h \
     ../../plugins/dm.conversation/CommandEditor.cpp \
     ../../plugins/dm.conversation/ConversationDialog.cpp \
     ../../plugins/dm.conversation/ConversationEntity.cpp \
     ../../plugins/dm.conversation/ConversationKeyExtractor.cpp \
     ../../plugins/dm.conversation/ConversationEditor.cpp \
     ../../plugins/fonts/FontLoader.cpp \
     ../../plugins/eventmanager/MouseEvents.cpp \
     ../../plugins/eventmanager/Modifiers.cpp \
     ../../plugins/mapdoom3/NodeImporter.cpp \
     ../../plugins/mapdoom3/Doom3PrefabFormat.cpp \
     ../../plugins/mapdoom3/primitiveparsers/BrushDef.cpp \
     ../../plugins/mapdoom3/primitiveparsers/BrushDef3.cpp \
     ../../plugins/mapdoom3/InfoFile.cpp \
     ../../plugins/mapdoom3/Doom3MapFormat.cpp \
     ../../plugins/dm.gui/plugin.cpp \
     ../../plugins/dm.gui/XDataSelector.cpp \
     ../../plugins/dm.gui/ReadableReloader.h \
     ../../plugins/dm.gui/GuiSelector.cpp \
     ../../plugins/dm.gui/XData.h \
     ../../plugins/dm.gui/ReadablePopulator.h \
     ../../plugins/dm.gui/ReadableEditorDialog.cpp \
     ../../plugins/dm.gui/XData.cpp \
     ../../plugins/dm.gui/XdFileChooserDialog.cpp \
     ../../plugins/dm.stimresponse/ResponseEffect.cpp \
     ../../plugins/dm.stimresponse/EffectEditor.cpp \
     ../../plugins/dm.stimresponse/plugin.cpp \
     ../../plugins/dm.stimresponse/StimEditor.cpp \
     ../../plugins/dm.stimresponse/SRPropertyRemover.cpp \
     ../../plugins/dm.stimresponse/CustomStimEditor.cpp \
     ../../plugins/dm.stimresponse/StimResponseEditor.cpp \
     ../../plugins/dm.stimresponse/StimTypes.cpp \
     ../../plugins/dm.stimresponse/ResponseEditor.cpp \
     ../../plugins/dm.stimresponse/SRPropertyLoader.cpp \
     ../../plugins/dm.stimresponse/ClassEditor.cpp \
     ../../plugins/dm.difficulty/plugin.cpp \
     ../../plugins/dm.difficulty/DifficultyDialog.cpp \
     ../../plugins/dm.difficulty/Setting.cpp \
     ../../plugins/dm.difficulty/DifficultyEditor.cpp \
     ../../plugins/filetypes/FileTypeRegistry.cpp \
     ../../plugins/entitylist/EntityList.cpp \
     ../../plugins/dm.objectives/ObjectivesEditor.cpp \
     ../../plugins/dm.objectives/Specifier.cpp \
     ../../plugins/dm.objectives/ObjectiveEntityFinder.h \
     ../../plugins/dm.objectives/LogicEditor.cpp \
     ../../plugins/dm.objectives/ComponentType.cpp \
     ../../plugins/dm.objectives/ObjectiveKeyExtractor.cpp \
     ../../plugins/dm.objectives/objectives.cpp \
     ../../plugins/dm.objectives/MissionLogicDialog.cpp \
     ../../plugins/dm.objectives/SpecifierType.cpp \
     ../../plugins/dm.objectives/ce/LocationComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/DistanceComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/ItemComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/InfoLocationComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/AIFindItemComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/ReadableOpenedComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/CustomComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/DestroyComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/ReadableClosedComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/ReadablePageReachedComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/AlertComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/PickpocketComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/CustomClockedComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/KillComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/KnockoutComponentEditor.cpp \
     ../../plugins/dm.objectives/ce/AIFindBodyComponentEditor.cpp \
     ../../plugins/dm.objectives/ComponentsDialog.cpp \
     ../../plugins/dm.objectives/ObjectiveEntity.cpp \
     ../../plugins/dm.objectives/DifficultyPanel.cpp \
     ../../plugins/dm.editing/plugin.cpp \
     ../../plugins/dm.editing/AIVocalSetPropertyEditor.cpp \
     ../../plugins/dm.editing/AIHeadPropertyEditor.cpp \
     ../../plugins/dm.editing/AIHeadChooserDialog.cpp \
     ../../plugins/dm.editing/FixupMapDialog.cpp \
     ../../plugins/dm.editing/AIVocalSetPreview.cpp \
     ../../plugins/dm.editing/AIVocalSetChooserDialog.cpp \
     ../../plugins/dm.editing/FixupMap.cpp \
     ../../plugins/image/jpeg.cpp \
     ../../plugins/script/ScriptWindow.cpp \
     ../../plugins/script/ScriptMenu.cpp \
     ../../plugins/script/ScriptingSystem.cpp \
     ../../plugins/uimanager/colourscheme/ColourSchemeEditor.cpp \
     ../../plugins/uimanager/FilterMenu.cpp \
     ../../plugins/uimanager/ParticlePreview.cpp \
     ../../plugins/uimanager/ToolbarManager.cpp \
     ../../plugins/uimanager/GroupDialog.cpp \
     ../../plugins/uimanager/MenuItem.cpp \
     ../../plugins/undo/UndoSystem.cpp \
     ../../plugins/grid/Grid.cpp \
     ../../plugins/wavefront/WaveFrontModule.cpp \
     ../../install/ui/ObjectivesEditor.glade \
     ../../install/ui/EntityClassChooser.glade \
     ../../install/ui/CamWnd.glade \
     ../../install/ui/AddPropertyDialog.glade

CATALOGS =  de.gmo

# Makevars gets inserted here. (Don't remove this line!)
# Makefile variables for PO directory in any package using GNU gettext.

# Usually the message domain is the same as the package name.
DOMAIN = $(PACKAGE)

# These two variables depend on the location of this directory.
subdir = install/i18n
top_builddir = ../..

# These options get passed to xgettext.
XGETTEXT_OPTIONS = --keyword=_ --keyword=N_ --qt

# This is the copyright holder that gets inserted into the header of the
# $(DOMAIN).pot file.  Set this to the copyright holder of the surrounding
# package.  (Note that the msgstr strings, extracted from the package's
# sources, belong to the copyright holder of the package.)  Translators are
# expected to transfer the copyright for their translations to this person
# or entity, or to disclaim their copyright.  The empty string stands for
# the public domain; in this case the translators are expected to disclaim
# their copyright.
COPYRIGHT_HOLDER = The Dark Mod Team and contributors

# This is the email address or URL to which the translators shall report
# bugs in the untranslated strings:
# - Strings which are not entire sentences, see the maintainer guidelines
#   in the GNU gettext documentation, section 'Preparing Strings'.
# - Strings which use unclear terms or require additional context to be
#   understood.
# - Strings which make invalid assumptions about notation of date, time or
#   money.
# - Pluralisation problems.
# - Incorrect English spelling.
# - Incorrect formatting.
# It can be your email address, or a mailing list address where translators
# can write to without being subscribed, or the URL of a web page through
# which the translators can contact you.
MSGID_BUGS_ADDRESS = http://thedarkmod.com

# This is the list of locale categories, beyond LC_MESSAGES, for which the
# message catalogs shall be used.  It is usually empty.
EXTRA_LOCALE_CATEGORIES =

.SUFFIXES:
.SUFFIXES: .po .gmo .mo .sed .sin .nop .po-create .po-update

.po.mo:
	@echo "$(MSGFMT) -c -o $@ $<"; \
	$(MSGFMT) -c -o t-$@ $< && mv t-$@ $@

.po.gmo:
	@lang=`echo $* | sed -e 's,.*/,,'`; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}rm -f $${lang}.gmo && $(GMSGFMT) -c --statistics --verbose -o $${lang}.gmo $${lang}.po"; \
	cd $(srcdir) && rm -f $${lang}.gmo && $(GMSGFMT) -c --statistics --verbose -o t-$${lang}.gmo $${lang}.po && mv t-$${lang}.gmo $${lang}.gmo

.sin.sed:
	sed -e '/^#/d' $< > t-$@
	mv t-$@ $@


all: check-macro-version all-yes

all-yes: stamp-po
all-no:

# Ensure that the gettext macros and this Makefile.in.in are in sync.
check-macro-version:
	@test "$(GETTEXT_MACRO_VERSION)" = "0.18" \
	  || { echo "*** error: gettext infrastructure mismatch: using a Makefile.in.in from gettext version $(GETTEXT_MACRO_VERSION) but the autoconf macros are from gettext version 0.18" 1>&2; \
	       exit 1; \
	     }

# $(srcdir)/$(DOMAIN).pot is only created when needed. When xgettext finds no
# internationalized messages, no $(srcdir)/$(DOMAIN).pot is created (because
# we don't want to bother translators with empty POT files). We assume that
# LINGUAS is empty in this case, i.e. $(POFILES) and $(GMOFILES) are empty.
# In this case, stamp-po is a nop (i.e. a phony target).

# stamp-po is a timestamp denoting the last time at which the CATALOGS have
# been loosely updated. Its purpose is that when a developer or translator
# checks out the package via CVS, and the $(DOMAIN).pot file is not in CVS,
# "make" will update the $(DOMAIN).pot and the $(CATALOGS), but subsequent
# invocations of "make" will do nothing. This timestamp would not be necessary
# if updating the $(CATALOGS) would always touch them; however, the rule for
# $(POFILES) has been designed to not touch files that don't need to be
# changed.
stamp-po: $(srcdir)/$(DOMAIN).pot
	test ! -f $(srcdir)/$(DOMAIN).pot || \
	  test -z "$(GMOFILES)" || $(MAKE) $(GMOFILES)
	@test ! -f $(srcdir)/$(DOMAIN).pot || { \
	  echo "touch stamp-po" && \
	  echo timestamp > stamp-poT && \
	  mv stamp-poT stamp-po; \
	}

# Note: Target 'all' must not depend on target '$(DOMAIN).pot-update',
# otherwise packages like GCC can not be built if only parts of the source
# have been downloaded.

# This target rebuilds $(DOMAIN).pot; it is an expensive operation.
# Note that $(DOMAIN).pot is not touched if it doesn't need to be changed.
$(DOMAIN).pot-update: $(POTFILES) $(srcdir)/POTFILES.in
	if LC_ALL=C grep 'GNU darkradiant' $(top_srcdir)/* 2>/dev/null | grep -v 'libtool:' >/dev/null; then \
	  package_gnu='GNU '; \
	else \
	  package_gnu=''; \
	fi; \
	if test -n '$(MSGID_BUGS_ADDRESS)' || test '$(PACKAGE_BUGREPORT)' = '@'PACKAGE_BUGREPORT'@'; then \
	  msgid_bugs_address='$(MSGID_BUGS_ADDRESS)'; \
	else \
	  msgid_bugs_address='$(PACKAGE_BUGREPORT)'; \
	fi; \
	case `$(XGETTEXT) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	  '' | 0.[0-9] | 0.[0-9].* | 0.1[0-5] | 0.1[0-5].* | 0.16 | 0.16.[0-1]*) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: $(XGETTEXT_OPTIONS)  \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	    ;; \
	  *) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: $(XGETTEXT_OPTIONS)  \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --package-name="$${package_gnu}darkradiant" \
	      --package-version='1.8.0' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	    ;; \
	esac
	test ! -f $(DOMAIN).po || { \
	  if test -f $(srcdir)/$(DOMAIN).pot; then \
	    cat < $(srcdir)/$(DOMAIN).pot > $(DOMAIN).1po && \
	    cat < $(DOMAIN).po > $(DOMAIN).2po && \
	    if cmp $(DOMAIN).1po $(DOMAIN).2po >/dev/null 2>&1; then \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(DOMAIN).po; \
	    else \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(srcdir)/$(DOMAIN).pot && \
	      mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	    fi; \
	  else \
	    mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	  fi; \
	}

# This rule has no dependencies: we don't need to update $(DOMAIN).pot at
# every "make" invocation, only create it when it is missing.
# Only "make $(DOMAIN).pot-update" or "make dist" will force an update.
$(srcdir)/$(DOMAIN).pot:
	$(MAKE) $(DOMAIN).pot-update

# This target rebuilds a PO file if $(DOMAIN).pot has changed.
# Note that a PO file is not touched if it doesn't need to be changed.
$(POFILES): $(srcdir)/$(DOMAIN).pot gather-po-files
	@lang=`echo $@ | sed -e 's,.*/,,' -e 's/\.po$$//'`; \
	if test -f "$(srcdir)/$${lang}.po"; then \
	  test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	  echo "$${cdcmd}$(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --lang=$${lang} $${lang}.po $(DOMAIN).pot"; \
	  cd $(srcdir) \
	    && { case `$(MSGMERGE_UPDATE) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	           '' | 0.[0-9] | 0.[0-9].* | 0.1[0-7] | 0.1[0-7].*) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) $${lang}.po $(DOMAIN).pot;; \
	           *) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --lang=$${lang} $${lang}.po $(DOMAIN).pot;; \
	         esac; \
	       }; \
	else \
	  $(MAKE) $${lang}.po-create; \
	fi


install: install-exec install-data
install-exec:
install-data: install-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    $(INSTALL_DATA) $(srcdir)/$$file \
			    $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	  for file in Makevars; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
install-data-no: all
install-data-yes: all
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  if test -r $$cat; then realcat=$$cat; else realcat=$(srcdir)/$$cat; fi; \
	  $(INSTALL_DATA) $$realcat $(DESTDIR)$$dir/$(DOMAIN).mo; \
	  echo "installing $$realcat as $(DESTDIR)$$dir/$(DOMAIN).mo"; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	      rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      ln -s ../LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      ln $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      cp -p $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      echo "installing $$realcat link as $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo"; \
	    fi; \
	  done; \
	done

install-strip: install

installdirs: installdirs-exec installdirs-data
installdirs-exec:
installdirs-data: installdirs-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	else \
	  : ; \
	fi
installdirs-data-no:
installdirs-data-yes:
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	    fi; \
	  done; \
	done

# Define this as empty until I found a useful application.
installcheck:

uninstall: uninstall-exec uninstall-data
uninstall-exec:
uninstall-data: uninstall-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
uninstall-data-no:
uninstall-data-yes:
	catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  for lc in LC_MESSAGES $(EXTRA_LOCALE_CATEGORIES); do \
	    rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	  done; \
	done

check: all

info dvi ps pdf html tags TAGS ctags CTAGS ID:

mostlyclean:
	rm -f stamp-poT
	rm -f core core.* $(DOMAIN).po $(DOMAIN).1po $(DOMAIN).2po *.new.po
	rm -fr *.o

clean: mostlyclean

distclean: clean
	rm -f Makefile Makefile.in POTFILES *.mo

maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f stamp-po $(GMOFILES)

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
dist distdir:
	$(MAKE) update-po
	@$(MAKE) dist2
# This is a separate target because 'update-po' must be executed before.
dist2: stamp-po $(DISTFILES)
	dists="$(DISTFILES)"; \
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  dists="$$dists Makevars.template"; \
	fi; \
	if test -f $(srcdir)/$(DOMAIN).pot; then \
	  dists="$$dists $(DOMAIN).pot stamp-po"; \
	fi; \
	if test -f $(srcdir)/ChangeLog; then \
	  dists="$$dists ChangeLog"; \
	fi; \
	for i in 0 1 2 3 4 5 6 7 8 9; do \
	  if test -f $(srcdir)/ChangeLog.$$i; then \
	    dists="$$dists ChangeLog.$$i"; \
	  fi; \
	done; \
	if test -f $(srcdir)/LINGUAS; then dists="$$dists LINGUAS"; fi; \
	for file in $$dists; do \
	  if test -f $$file; then \
	    cp -p $$file $(distdir) || exit 1; \
	  else \
	    cp -p $(srcdir)/$$file $(distdir) || exit 1; \
	  fi; \
	done

# Custom target added to gather the .po files in the top-level directory and
# with the correct names. The Win32 gettext implementation keeps them next to
# the .mo files.
gather-po-files:
	for dir in *; do \
		if test -d $${dir}; then \
			cp $${dir}/LC_MESSAGES/darkradiant.po $${dir}.po; \
		fi; \
	done

update-po: Makefile
	$(MAKE) $(DOMAIN).pot-update
	test -z "$(UPDATEPOFILES)" || $(MAKE) $(UPDATEPOFILES)
	$(MAKE) update-gmo

# General rule for creating PO files.

.nop.po-create:
	@lang=`echo $@ | sed -e 's/\.po-create$$//'`; \
	echo "File $$lang.po does not exist. If you are a translator, you can create it through 'msginit'." 1>&2; \
	exit 1

# General rule for updating PO files.

.nop.po-update:
	@lang=`echo $@ | sed -e 's/\.po-update$$//'`; \
	if test "$(PACKAGE)" = "gettext-tools"; then PATH=`pwd`/../src:$$PATH; fi; \
	tmpdir=`pwd`; \
	echo "$$lang:"; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}$(MSGMERGE) $(MSGMERGE_OPTIONS) --lang=$$lang $$lang.po $(DOMAIN).pot -o $$lang.new.po"; \
	cd $(srcdir); \
	if { case `$(MSGMERGE) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	       '' | 0.[0-9] | 0.[0-9].* | 0.1[0-7] | 0.1[0-7].*) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	       *) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) --lang=$$lang -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	     esac; \
	   }; then \
	  if cmp $$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	    rm -f $$tmpdir/$$lang.new.po; \
	  else \
	    if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	      :; \
	    else \
	      echo "msgmerge for $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	      exit 1; \
	    fi; \
	  fi; \
	else \
	  echo "msgmerge for $$lang.po failed!" 1>&2; \
	  rm -f $$tmpdir/$$lang.new.po; \
	fi

$(DUMMYPOFILES):

update-gmo: Makefile gather-po-files $(GMOFILES)
	@:

# Recreate Makefile by invoking config.status. Explicitly invoke the shell,
# because execution permission bits may not work on the current file system.
# Use /bin/bash, which is the shell determined by autoconf for the use by its
# scripts, not $(SHELL) which is hardwired to /bin/sh and may be deficient.
Makefile: Makefile.in.in Makevars $(top_builddir)/config.status POTFILES.in LINGUAS
	cd $(top_builddir) \
	  && /bin/bash ./config.status $(subdir)/$@.in po-directories

force:

# Tell versions [3.59,3.63) of GNU make not to export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
