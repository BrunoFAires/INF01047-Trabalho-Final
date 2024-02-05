#version 330 core

// Atributos de fragmentos recebidos como entrada ("in") pelo Fragment Shader.
// Neste exemplo, este atributo foi gerado pelo rasterizador como a
// interpolação da posição global e a normal de cada vértice, definidas em
// "shader_vertex.glsl" e "main.cpp".
in vec4 position_world;
in vec4 normal;

// Posição do vértice atual no sistema de coordenadas local do modelo.
in vec4 position_model;

// Coordenadas de textura obtidas do arquivo OBJ (se existirem!)
in vec2 texcoords;

// Matrizes computadas no código C++ e enviadas para a GPU
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// Identificador que define qual objeto está sendo desenhado no momento
#define SPHERE 0
#define BUNNY  1
#define PLANE  2
uniform int object_id;

// Parâmetros da axis-aligned bounding box (AABB) do modelo
uniform vec4 bbox_min;
uniform vec4 bbox_max;
in vec4 buttonColor;

// Variáveis para acesso das imagens de textura
uniform sampler2D TextureImage0;
uniform sampler2D TextureImage1;
uniform sampler2D TextureImage2;
uniform sampler2D TextureImage3;
uniform sampler2D TextureImage4;
uniform sampler2D TextureImage5;

// O valor de saída ("out") de um Fragment Shader é a cor final do fragmento.
out vec4 color;

// Constantes
#define M_PI   3.14159265358979323846
#define M_PI_2 1.57079632679489661923

void main()
{
    // Obtemos a posição da câmera utilizando a inversa da matriz que define o
    // sistema de coordenadas da câmera.
    vec4 origin = vec4(0, 50.0, 20.0, 1.0);
    vec4 camera_position = inverse(view) * origin;

    // O fragmento atual é coberto por um ponto que percente à superfície de um
    // dos objetos virtuais da cena. Este ponto, p, possui uma posição no
    // sistema de coordenadas global (World coordinates). Esta posição é obtida
    // através da interpolação, feita pelo rasterizador, da posição de cada
    // vértice.
    vec4 p = position_world;

    // Normal do fragmento atual, interpolada pelo rasterizador a partir das
    // normais de cada vértice.
    vec4 n = normalize(normal);

    // Vetor que define o sentido da fonte de luz em relação ao ponto atual.
    vec4 l = normalize(vec4(5.0,5.0,5.0,0.0));

    // Vetor que define o sentido da câmera em relação ao ponto atual.
    vec4 v = normalize(camera_position - p);
     vec4 h = normalize(v+l);


    // Coordenadas de textura U e V
    float U = 0.0;
    float V = 0.0;

    vec3 Kd; // Refletância difusa
    vec3 Ks; // Refletância especular
    vec3 Ka; // Refletância ambiente
    float q; // Expoente especular para o modelo de iluminação de Phong
    float q_linha; // Expoente especular para o modelo de iluminação de Blinn-Phong

     if ( object_id == 0 )
    {
        U = texcoords.x;
        V = texcoords.y;

        vec3 Kd0 = texture(TextureImage2, vec2(U,V)).rgb;
        Ks = vec3(1.0,1.0,1.0);
        Ka = texture(TextureImage2, vec2(U,V)).rgb;
        q_linha = 50.0;
        vec3 I = vec3(1.0,1.0,1.0);

        vec3 Ia = vec3(0.2,0.2,0.2);

        vec3 lambert = Kd0*I*max(0,dot(n,l));

        vec3 ambient_term = Ka*Ia;

        vec3 blinn_phong_specular_term  = Ks*I*pow(max(0, dot(n,h)), q_linha);

        color.rgb = lambert + ambient_term + blinn_phong_specular_term;
        color.a = 1;

        color.rgb = pow(color.rgb, vec3(1.0,1.0,1.0)/2.2);
        return;
        return;
    }else    if ( object_id == 1 )
    {
        // Coordenadas de textura do plano, obtidas do arquivo OBJ.
        U = texcoords.x;
        V = texcoords.y;

        vec3 Kd0 = texture(TextureImage1, vec2(U,V)).rgb;
        Ks = vec3(1.0,1.0,1.0);         // Superfície 100% difusa
        Ka = texture(TextureImage1, vec2(U,V)).rgb;                   // Refletância ambiente no modelo RGB = metade da refletância difusa
        q_linha = 50.0;
        vec3 I = vec3(1.0,1.0,1.0); // PREENCHA AQUI o espectro da fonte de luz

        // Espectro da luz ambiente
        vec3 Ia = vec3(0.2,0.2,0.2); // PREENCHA AQUI o espectro da luz ambiente
        q_linha = 50.0;
        // Equação de Iluminação
        vec3 lambert = Kd0*I*max(0,dot(n,l));

        vec3 ambient_term = Ka*Ia; // PREENCHA AQUI o termo ambiente

        vec3 blinn_phong_specular_term  = Ks*I*pow(max(0, dot(n,h)), q_linha);

        color.rgb = lambert + ambient_term;
        color.a = 1;
        color.rgb = pow(color.rgb, vec3(1.0,1.0,1.0)/2.2);
        return;
    }else    if ( object_id == 2 )
    {
        color = buttonColor;
        return;
    }
    
    else    if ( object_id == 3 )
    {
        U = texcoords.x;
        V = texcoords.y;

        vec3 Kd0 = texture(TextureImage3, vec2(U,V)).rgb;
        Ks = vec3(1.0,1.0,1.0);
        Ka = texture(TextureImage3, vec2(U,V)).rgb;
        vec3 I = vec3(1.0,1.0,1.0);
        vec3 Ia = vec3(0.2,0.2,0.2);
        vec3 lambert = Kd0*I*max(0,dot(n,l));

        vec3 ambient_term = Ka*Ia;

        color.rgb = lambert + ambient_term;
        color.rgb = pow(color.rgb, vec3(1.0,1.0,1.0)/2.2);
        return;
    }

        else    if ( object_id == 4 )
    {
        U = 150/texcoords.x;
        V = 150/texcoords.y;

        vec3 Kd0 = texture(TextureImage5, vec2(U,V)).rgb;
        Ks = vec3(1.0,1.0,1.0);
        Ka = texture(TextureImage5, vec2(U,V)).rgb;
        vec3 I = vec3(1.0,1.0,1.0);
        vec3 Ia = vec3(0.2,0.2,0.2);
        vec3 lambert = Kd0*I*max(0,dot(n,l));

        vec3 ambient_term = Ka*Ia;

        color.rgb = lambert + ambient_term;
        color.rgb = pow(color.rgb, vec3(1.0,1.0,1.0)/2.2);
        return;
    }
}
