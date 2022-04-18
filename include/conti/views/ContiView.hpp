#pragma once

#include "conti/listeners/ContiListener.hpp"
#include <QWidget>

class ContiModel;

class ContiView : public QWidget
                , public ContiListener
{
    Q_OBJECT

public:
    explicit ContiView(ContiModel* model, QWidget* parent=nullptr);
    ~ContiView();

private:
    // We hold a weak reference to the model (ContiModel) so we can listen
    // to it
    ContiModel* model_;
};
