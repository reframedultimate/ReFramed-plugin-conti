#pragma once

#include "rfcommon/SessionListener.hpp"
#include "rfcommon/ListenerDispatcher.hpp"
#include "rfcommon/Reference.hpp"

namespace rfcommon {
    class Session;
}

class ContiListener;

class ContiModel : public rfcommon::SessionListener
{
public:
    void setSession(rfcommon::Session* session);
    void clearSession(rfcommon::Session* session);

    rfcommon::ListenerDispatcher<ContiListener> dispatcher;

private:
    // RunningGameSession events
    void onRunningGameSessionPlayerNameChanged(int playerIdx, const rfcommon::SmallString<15>& name) override {}
    void onRunningGameSessionSetNumberChanged(rfcommon::SetNumber number) override {}
    void onRunningGameSessionGameNumberChanged(rfcommon::GameNumber number) override {}
    void onRunningGameSessionFormatChanged(const rfcommon::SetFormat& format) override {}
    void onRunningGameSessionWinnerChanged(int winnerPlayerIdx) override {}

    // RunningSession events
    void onRunningSessionNewUniquePlayerState(int playerIdx, const rfcommon::PlayerState& state) override;
    void onRunningSessionNewPlayerState(int playerIdx, const rfcommon::PlayerState& state) override {}
    void onRunningSessionNewUniqueFrame(const rfcommon::SmallVector<rfcommon::PlayerState, 8>& states) override {}
    void onRunningSessionNewFrame(const rfcommon::SmallVector<rfcommon::PlayerState, 8>& states) override {}

private:
    rfcommon::Reference<rfcommon::Session> session_;
};
