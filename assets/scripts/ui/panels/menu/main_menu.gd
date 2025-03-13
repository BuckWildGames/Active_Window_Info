extends UIState

@onready var version_label: Label = $VersionLabel
@onready var label: Label = $Buttons/Label

@export var overlay: Node

var active_window_info = null


func _ready():
	# Check if the extension is available
	if ClassDB.class_exists("ActiveWindowInfo"):
		active_window_info = ActiveWindowInfo.new()
	else:
		print("ActiveWindowInfo extension not found!")


func _process(_delta):
	if active_window_info:
		var window_info = active_window_info.get_active_window_info()
		print("Active Window Info: ", window_info)


func enter(previous : String):
	super.enter(previous)
	#version_label.set_text("Version: " +ConfigManager.get_version())


func button_pressed(button: String) -> void:
	match button:
		"overlay":
			if overlay.is_overlay_enabled():
				overlay.disable_overlay()
				label.set_visible(false)
				print("Disabled Overlay")
			else:
				overlay.enable_overlay()
				label.set_visible(true)
				print("Enabled Overlay")


func _on_quit(quit: String) -> void:
	if quit == "Yes":
		get_tree().quit()
