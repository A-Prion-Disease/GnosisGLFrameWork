#version 430 core
out vec4 FragColor;

in vec4 PointColor;
in vec2 FragTexCords;

in float FragTexIndex;
in float mixRatio;

uniform sampler2D uniTexture[2];

void main(){

int index = int(FragTexIndex);


FragColor = mix(texture(uniTexture[index], FragTexCords), PointColor, mixRatio);

	   	   }

