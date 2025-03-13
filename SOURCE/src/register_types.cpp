#include "register_types.h"
#include "active_window_info.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_active_window_info_module(ModuleInitializationLevel p_level) {
    if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        // Register the ActiveWindowInfo class
        ClassDB::register_class<ActiveWindowInfo>();
    }
}

void uninitialize_active_window_info_module(ModuleInitializationLevel p_level) {
    // Cleanup if needed
}

extern "C" {
GDExtensionBool GDE_EXPORT active_window_info_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

    init_obj.register_initializer(initialize_active_window_info_module);
    init_obj.register_terminator(uninitialize_active_window_info_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}
}