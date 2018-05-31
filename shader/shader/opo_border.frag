#version 130

uniform sampler2D texture;

vec2 step = vec2(1, 1) / textureSize(texture, 0);

float adj(ivec2 v)
{
	return (texture2D(texture, vec2(gl_TexCoord[0].x + float(step.x) * v.x,
		gl_TexCoord[0].y + float(step.y) * v.y)).a);
}

float aura(int n)
{
	float f = adj(ivec2(1, 0));
	float mean = 0;

	for (int x = -n; x < n; x++)
		for (int y = -n; y < n; y++)
			f = max(adj(ivec2(x, y)), f);
	mean = clamp(mean, 0, 1);
	return (f);
}

void main()
{
  	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	if (pixel.a < 1) {
		float f = aura(2);
		gl_FragColor = vec4((1 - gl_TexCoord[0].xy), 1, f);
	}
	else
		gl_FragColor = pixel;
}
