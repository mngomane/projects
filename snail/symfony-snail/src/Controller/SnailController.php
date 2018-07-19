<?php

namespace App\Controller;

use App\Service\Snail\Shifting;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Request;

class SnailController extends AbstractController
{
    public function index(Request $request, Shifting $snailShifting)
    {
        $dimension = (int)$request->query->get('n', 1);
        if ($dimension < 1) {
            $dimension = 1;
        }

        $matrix    = [];
        $index     = 0;
        while (++$index < $dimension ** 2 + 1) {
            $matrix[$snailShifting->getIndex($index, $dimension)] = $index;
        }

        return $this->render('Snail/index.html.twig', [
            'dimension' => $dimension,
            'matrix'    => $matrix,
        ]);
    }
}
