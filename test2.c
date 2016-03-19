r x1 = -2.1
définir x2 = 0.6
définir y1 = -1.2
définir y2 = 1.2
définir zoom = 100 // pour une distance de 1 sur le plan, on a 100 pixel sur l'image
définir iteration_max = 50

définir image_x = (x2 - x1) * zoom
définir image_y = (y2 - y1) * zoom

Pour x = 0 tant que x < image_x par pas de 1 
	Pour y = 0 tant que y < image_y par pas de 1
		définir c_r = x / zoom + x1
		définir c_i = y / zoom + y1
		définir z_r = 0
		définir z_i = 0
		définir i = 0

		Faire
			définir tmp = z_r
			z_r = z_r*z_r - z_i*z_i + c_r
			z_i = 2*z_i*tmp + c_i
			i = i+1
		Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

		si i = iteration_max
			dessiner en noir le pixel de coordonné (x; x)
		sinon
			dessiner avec couleur rgb(0, 0, i*255/iterations_max) le pixel de coordonné (x; x)
		finSi
	finPour
finPour
