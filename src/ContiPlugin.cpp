#include "conti/ContiPlugin.hpp"
#include "conti/models/ContiModel.hpp"
#include "conti/views/ContiView.hpp"
#include "rfcommon/RunningGameSession.hpp"
#include "rfcommon/SavedGameSession.hpp"

// ----------------------------------------------------------------------------
ContiPlugin::ContiPlugin(RFPluginFactory* factory)
    : RealtimePlugin(factory)
    , model_(new ContiModel)
{
}

// ----------------------------------------------------------------------------
ContiPlugin::~ContiPlugin()
{
}

// ----------------------------------------------------------------------------
QWidget* ContiPlugin::createView()
{
    // Create new instance of view. The view registers as a listener to this model
    return new ContiView(model_.get());
}

// ----------------------------------------------------------------------------
void ContiPlugin::destroyView(QWidget* view)
{
    // ReFramed no longer needs the view, delete it
    delete view;
}

// ----------------------------------------------------------------------------
void ContiPlugin::setSavedGameSession(rfcommon::SavedGameSession* session)
{
    model_->setSession(session);
}

// ----------------------------------------------------------------------------
void ContiPlugin::clearSavedGameSession(rfcommon::SavedGameSession* session)
{
    model_->clearSession(session);
}

