#include "rendering_server.h"

namespace zylann::godot {

void get_shader_parameter_list(const RID &shader_rid, StdVector<ShaderParameterInfo> &out_parameters) {
#if defined(ZN_GODOT)
	List<PropertyInfo> params;
	RenderingServer::get_singleton()->get_shader_parameter_list(shader_rid, &params);
	// I'd like to use ConstIterator since I only read that list but that isn't possible :shrug:
	for (List<PropertyInfo>::Iterator it = params.begin(); it != params.end(); ++it) {
		const PropertyInfo property = *it;
		ShaderParameterInfo pi;
		pi.type = property.type;
		pi.name = property.name;
		out_parameters.push_back(pi);
	}

#elif defined(ZN_GODOT_EXTENSION)
	const Array properties = RenderingServer::get_singleton()->get_shader_parameter_list(shader_rid);
	const String type_key = "type";
	const String name_key = "name";
	for (int i = 0; i < properties.size(); ++i) {
		Dictionary d = properties[i];
		ShaderParameterInfo pi;
		pi.type = Variant::Type(int(d[type_key]));
		pi.name = d[name_key];
		out_parameters.push_back(pi);
	}
#endif
}

String get_current_rendering_method() {
	// TODO This is not well exposed at the moment.
	// See https://github.com/godotengine/godot/pull/85430
#if defined(ZN_GODOT)
	return OS::get_singleton()->get_current_rendering_method();
#elif defined(ZN_GODOT_EXTENSION)
	return "<unable to get current rendering method, Godot doesn't expose it>";
#endif
}

} // namespace zylann::godot
