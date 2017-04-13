/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:33:15 by jeexpert          #+#    #+#             */
/*   Updated: 2017/04/12 13:33:22 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ENV_H
# define RT_ENV_H

# include <OpenCL/opencl.h>
# include "utils/rt_math.h"

# define EPSILON 0.00001f
# define SCENE 0
# define CAMERA (SCENE + 1)

# define OBJECTS (CAMERA + 1)
# define SPHERE (OBJECTS)
# define PLANE (SPHERE + 1)
# define CYLINDER (PLANE + 1)
# define CONE (CYLINDER + 1)
# define TRIANGLE (CONE + 1)
# define DISK (TRIANGLE + 1)
# define CYLINDERINF (DISK + 1)
# define CONEINF (CYLINDERINF + 1)
# define PARABOLOID (CONEINF + 1)
# define ELLIPSOID (PARABOLOID + 1)
# define TORUS (ELLIPSOID + 1)
# define SOR (TORUS + 1)
# define END_OBJECTS (SOR)

# define LIGHTS (END_OBJECTS + 1)
# define SPOTLIGHT (LIGHTS)
# define POINTLIGHT (SPOTLIGHT + 1)
# define DIRLIGHT (POINTLIGHT + 1)
# define END_LIGHTS (DIRLIGHT)

# define MATERIAL (END_LIGHTS + 1)
# define TEXTURE (MATERIAL + 1)
# define RENDER (TEXTURE + 1)

// Pour le parser et le CL du mod de rendu
# define RENDERMODE (RENDER + 1)
# define RENDERMODE_SEPIA (RENDERMODE)
# define RENDERMODE_GRIS (RENDERMODE_SEPIA + 1)
# define RENDERMODE_FILTER (RENDERMODE_GRIS + 1)
# define RENDERMODE_ADD (RENDERMODE_FILTER + 1)
# define RENDERMODE_NEGATIF (RENDERMODE_ADD + 1)
# define RENDERMODE_CARTOON (RENDERMODE_NEGATIF + 1)
# define RENDERMODE_ANTI_ALIASING (RENDERMODE_CARTOON + 1)
# define END_RENDERMODE (RENDERMODE_ANTI_ALIASING)

typedef struct	s_cam
{
	VEC3	position;
	VEC3	rotation;
}				t_cam;

typedef struct	s_objects
{
	VEC4		color;
	VEC3		position;
	VEC3		rotation;
	VEC3		normal;
	VEC3		endpos; // position final cylindre et cone
	int			type;
	int			material_id;
	int			texture_id;
	int			in_object;
	float		radius;
	float		radius2; // petit radius pour torus
	float		a; // coefficient pour sor
	float		b; // pour sor
	float		c; // pour sor
	float		d; // pour sor
	float		dist; // distance des point pour parabol, epsilloid
}				t_objects;

typedef struct	s_light
{
	int			type;
	VEC3		position;
	VEC4		color;
	float		attenuation;
	VEC3		direction;
	float		angle;
}				t_light;

typedef struct	s_material
{
	VEC4		ambient_color;
	VEC4		specular_color;
	int			blinn;
	float		shininess;
	float		reflection;
	float		refraction;
	float		damier;
	int			perlin;
	float		refract_coef;
}				t_material;

typedef struct	s_scene
{
	char		*name;
	int			width;
	int			height;
	float		znear;
	float		zfar;
	float		fov;
	float		focale;
	int			max_reflect;
	int			max_refract;
	int			max_object;
	int			max_material;
	int			max_light;
	int			max_texture;
	int			render_debug;
	int			render_mod;
	VEC4		render_filter;
}				t_scene;

typedef struct	s_interface
{
	int		index;
	int		type;
}				t_interface;

typedef struct	s_env
{
	t_scene		scene;
	t_cam		camera;
	t_interface	interface;
	t_objects	*objects;
	t_light		*light;
	t_material	*material;
}				t_env;

t_env				*env_get(void);
void				env_init(void);
#endif
