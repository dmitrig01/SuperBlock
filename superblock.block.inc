<?php

class SuperBlock {
  protected $inputs;
  protected $context;
  function __construct($inputs, $context) {
    $this->inputs = $inputs;
    $this->context = $context;
  }
}

class SuperBlockNodeFusion extends SuperBlock {
  function render() {
    return drupal_render(node_view($this->inputs['node1']->get())) . drupal_render(node_view($this->inputs['node2']->get()));
  }
}
