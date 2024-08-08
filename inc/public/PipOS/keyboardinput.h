#include "inputeventhandler.h"

namespace PipOS {
class KeyboardEventHandler : public InputEventHandler
{
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};
} // namespace PipOS
