#include "conti/views/ContiView.hpp"
#include "conti/models/ContiModel.hpp"

// ----------------------------------------------------------------------------
ContiView::ContiView(ContiModel* model, QWidget* parent)
    : QWidget(parent)
    , model_(model)
{
    model_->dispatcher.addListener(this);
}

// ----------------------------------------------------------------------------
ContiView::~ContiView()
{
    model_->dispatcher.removeListener(this);
}
