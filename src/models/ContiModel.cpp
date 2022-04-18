#include "conti/models/ContiModel.hpp"
#include "conti/listeners/ContiListener.hpp"
#include "rfcommon/Session.hpp"

// ----------------------------------------------------------------------------
void ContiModel::setSession(rfcommon::Session* session)
{
    assert(session_.isNull());

    // Increments refcount to session object
    session_ = session;

    // We want to be notified of any new frame data that gets added to the
    // session in the future
    session_->dispatcher.addListener(this);
}

// ----------------------------------------------------------------------------
void ContiModel::clearSession(rfcommon::Session* session)
{
    if (session_.isNull())
        return;

    // Stop listening to events
    session_->dispatcher.removeListener(this);

    // Release our reference to the session. This decrements the refcount.
    session_.drop();
}

// ----------------------------------------------------------------------------
void ContiModel::onRunningSessionNewUniquePlayerState(int playerIdx, const rfcommon::PlayerState& state)
{
}
