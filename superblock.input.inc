<?php

class SuperBlockInput {
  protected $value;
  protected $context;

  function form() {}
  function form_submit($form_value) {}

  function get() {}
  function set($value) {
    $this->value = $value;
  }
  function __construct($context) {
    $this->context = $context;
  }
}

class SuperBlockInputNode extends SuperBlockInput {
  function get() {
    $type = $this->value['type'];
    if ($type == 'context') {
      return $this->context->get($this->value['value']);
    }
    else {
      return node_load($this->value['value']);
    }
  }
}
