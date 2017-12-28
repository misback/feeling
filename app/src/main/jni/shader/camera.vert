const char* camera_play_vert = STRINGIFY(

attribute 	vec2 a_Position;
attribute 	vec2 a_Textcoord;
uniform 	mat4 u_MvpMatrix;
varying 	vec2 v_CamTextcoord;

void main()
{
	gl_Position     = u_MvpMatrix * vec4(a_Position, 0.0, 1.0);
	v_CamTextcoord  = a_Textcoord;
}
);