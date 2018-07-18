<?php

namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Request;

class SnailController extends AbstractController
{
    public function index(Request $request)
    {
        $dimension = (int)$request->query->get('n', 1);
        $matrix    = [];
        $index     = 0;
        while (++$index < $dimension ** 2 + 1) {
            $matrix[] = $index;
        }

        return $this->render('Snail/index.html.twig', [
            'dimension' => $dimension,
            'matrix'    => $matrix,
        ]);
    }
}
