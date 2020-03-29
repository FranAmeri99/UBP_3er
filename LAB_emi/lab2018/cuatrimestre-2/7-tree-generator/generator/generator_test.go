package generator

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestGenerateTreeOK(t *testing.T) {
	_, err := GenerateTree("../input.txt")
	assert.Nil(t, err)
}

func TestGenerateTreeFileNotExists(t *testing.T) {
	_, err := GenerateTree("../esteArchivoNoExiste.txt")
	assert.NotNil(t, err)
}