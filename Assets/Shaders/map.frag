#version 330

uniform vec3 kA = vec3(0.5, 0.5, 0.5);
uniform vec3 kD = vec3(0.8, 0.8, 0.8);
uniform vec3 kS = vec3(0.6, 0.6, 0.6);

uniform sampler2D tDiffuse;


in vec3 player_location;
in vec3 fTexcoord;
in vec3 fColour;
in vec3 fNormal;
in vec3 fLightDirection;
in vec3 fViewer;
in vec3 fLightReflection;

out vec3 colour;

void main() {
    vec2 position = vec2(player_location.x, -player_location.z);
    vec2 uvs = (fTexcoord.st - vec2(0.5, 0.5)) * 0.3 + ((position.xy + vec2(350,350)) / vec2(750,750)) ;

    vec4 diffuse = texture(tDiffuse, uvs.st );
    if (diffuse.a < 0.1) { discard; }
    colour = kA * diffuse.rgb + diffuse.rgb * max(dot(fLightDirection, fNormal), 0.0);
}


