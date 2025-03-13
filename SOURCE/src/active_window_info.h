#ifndef ACTIVE_WINDOW_INFO_H
#define ACTIVE_WINDOW_INFO_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/dictionary.hpp>

namespace godot {

class ActiveWindowInfo : public Object {
    GDCLASS(ActiveWindowInfo, Object);

protected:
    static void _bind_methods();

public:
    ActiveWindowInfo() {}

    // Method to get active window information
    Dictionary get_active_window_info();
};

} // namespace godot

#endif // ACTIVE_WINDOW_INFO_H