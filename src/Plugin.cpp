#include "conti/PluginConfig.hpp"
#include "conti/ContiPlugin.hpp"
#include "rfcommon/PluginInterface.hpp"

// Gets called when the main application wants to create your plugin
static rfcommon::Plugin* createContiPlugin(RFPluginFactory* factory)
{
    return new ContiPlugin(factory);
}

// Gets called when the main application removes your plugin from its
// list. You have to delete the object here.
static void destroyContiPlugin(rfcommon::Plugin* model)
{
    delete model;
}

// This is a list of create/destroy functions which the main application uses
// to instantiate your plugins. You can have multiple plugins in a single
// shared libary, but in this case we only have one.
static RFPluginFactory factories[] = {
    {createContiPlugin, destroyContiPlugin, RFPluginType::REALTIME,
    {"Conti",
     "misc > misc",  // category > sub-category
     "TheComet",  // your name
     "TheComet#5387, @TheComet93",  // various contact details
     ""}},

    {0}  // List must be terminated with a NULL or bad things happen!
};

static int start(uint32_t version, const char** error)
{
    // Gets called right after shared library is loaded. Initialize global state
    // here
    // 
    // Version of ReFramed gets passed in here. Return 0 if you're compatible, 
    // any other number (-1) if otherwise. If you return non-zero, write an
    // error message to *error so the main application can tell the user what
    // went wrong.
    return 0;
}

static void stop()
{
    // Gets called before the shared libary is unloaded. Clean up global state here.
}

DEFINE_PLUGIN(factories, start, stop)

