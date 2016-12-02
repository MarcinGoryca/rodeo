/*
 | --------------------------------------------------------------------------------------------------
 |     Laura Project
 |
 |     marcin.goryca@gmail.com
 |     http://marcingoryca.pl
 |
 |     License Information
 |
 |     The MIT License (MIT)
 |     Copyright (c) 2016 Marcin Goryca
 |
 |     Permission is hereby granted, free of charge,
 |     to any person obtaining a copy of this software
 |     and associated documentation files (the "Software"),
 |     to deal in the Software without restriction,
 |     including without limitation the rights to use,
 |     copy, modify, merge, publish, distribute, sublicense,
 |     and/or sell copies of the Software,
 |     and to permit persons to whom the Software is furnished to do so,
 |     subject to the following conditions:
 |
 |     The above copyright notice and this permission notice
 |     shall be included in all copies or substantial portions of the Software.
 |
 |     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 |     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 |     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 |     IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 |     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 |     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 |     IN THE SOFTWARE.
 |---------------------------------------------------------------------------------------------------
 */

//#include "io\filefbx.h"
//
//namespace engineio
//{
///**
// *-------------------------------------------
// * @file filefbx.cpp
// * <p>Part of Rodeo IO Module</p>
// * <h2>Rodeo Game Engine</h2>
// * @author Copyright (c) 2010-2014 Marcin Goryca
// * !IMPORTANT NOTES!
// * This module uses FBX_SDK for VS2010
// * Based on ImportScene.cxx
// *------------------------------------------
// */
//bool FileFBX::import(const char* filename)
//{
//    fbx_laurar_ = FbxManager::Create();
//
//    FbxIOSettings* ios = FbxIOSettings::Create(fbx_laurar_, IOSROOT);
//
//    fbx_laurar_->SetIOSettings(ios);
//
//    FbxImporter* importer = FbxImporter::Create(fbx_laurar_, "");
//
//    if(!importer->Initialize(filename, -1, fbx_laurar_->GetIOSettings()))
//    {
//        std::string error = "FBX Importer Failed.\n";
//        error += "Error: ";
//        //error += importer->GetLastErrorString();
//
//        MessageBox(NULL, error.c_str(), enginecore::HEADER, enginecore::errIconOK);
//        return false;
//    }
//
//    FbxScene* scene = FbxScene::Create(fbx_laurar_, "rodeo_scene");
//    importer->Import(scene);
//    importer->Destroy();
//
//    readFile(scene);
//
//    return true;
//}
//
////------------------------------
//
//void FileFBX::readMesh(FbxNode* node)
//{
//    FbxMesh* mesh = (FbxMesh*)node->GetNodeAttribute();
//
//    engineentity::Mesh tmp_mesh;
//
//    ZeroMemory(&tmp_mesh, sizeof(tmp_mesh));
//
////  DISPLAY CONTROL POINTS
//
//    tmp_mesh.mesh_name_ = node->GetName();
//    int control_points_count = mesh->GetControlPointsCount();
//    FbxVector4* control_points = mesh->GetControlPoints();
//
//    tmp_mesh.vertex_count_ = control_points_count;
//    tmp_mesh.vertex_ = new engineentity::MeshVertex[tmp_mesh.vertex_count_];
//    tmp_mesh.normal_ = new engineentity::MeshNormal[tmp_mesh.vertex_count_];
//    
//    for(int i=0; i < control_points_count; ++i)
//    {
//        tmp_mesh.vertex_[i].vertex_.x_ = control_points[i].mData[0];
//        tmp_mesh.vertex_[i].vertex_.y_ = control_points[i].mData[1];
//        tmp_mesh.vertex_[i].vertex_.z_ = control_points[i].mData[2];
//
//        for(int j=0; j < mesh->GetElementNormalCount(); ++j)
//        {
//            FbxGeometryElementNormal* normals = mesh->GetElementNormal(j);
//
//            if(normals->GetMappingMode() == FbxGeometryElement::eByControlPoint)
//            {
//                if(normals->GetReferenceMode() == FbxGeometryElement::eDirect)
//                {
//                    tmp_mesh.normal_[j].normal_.x_ = normals->GetDirectArray().GetAt(j).mData[0];
//                    tmp_mesh.normal_[j].normal_.y_ = normals->GetDirectArray().GetAt(j).mData[1];
//                    tmp_mesh.normal_[j].normal_.z_ = normals->GetDirectArray().GetAt(j).mData[2];
//                }
//            }
//        }	// j loop
//    }	// i loop
//
//    //polygon data
//
////  DISPLAY POLYGONS
//
//    int vertex_id = 0;
//    int polygon_count = mesh->GetPolygonCount();
//
//    tmp_mesh.face_count_ = static_cast<enginecore::ui>(polygon_count);
//
//    tmp_mesh.triangle_ = new engineentity::MeshTriangle[tmp_mesh.face_count_];
//
//    for(int i=0; i < polygon_count; ++i)
//    {
//        for(int j=0; j < mesh->GetElementPolygonGroupCount(); ++j)
//        {
//            FbxGeometryElementPolygonGroup* polygon_group = mesh->GetElementPolygonGroup(1);
//
//            switch(polygon_group->GetMappingMode())
//            {
//            case FbxGeometryElement::eByPolygon:
//                if(polygon_group->GetReferenceMode() == FbxGeometryElement::eIndex)
//                {
//                    int polygon_group_id = polygon_group->GetIndexArray().GetAt(i);
//                    break;
//                }
//            }
//        }	// j loop
//
//        int polygon_size = mesh->GetPolygonSize(i);
//        engineentity::MeshTriangle mesh_triangle;
//
//        for(int k = 0; k < polygon_size; ++k)
//        {
//            int control_point_index = mesh->GetPolygonVertex(i, k);
//
//            //mesh_triangle.tri[k] = static_cast<us>(control_point_index);
//
//            tmp_mesh.triangle_[i].triangle_[k] = static_cast<enginecore::us>(control_point_index);
//
//            for(int l = 0; l < mesh->GetElementVertexColorCount(); ++l)
//            {
//                FbxGeometryElementVertexColor* vertex_color = mesh->GetElementVertexColor(i);
//
//                switch(vertex_color->GetMappingMode())
//                {
//                case FbxGeometryElement::eByControlPoint:
//
//                    switch(vertex_color->GetReferenceMode())
//                    {
//                    case FbxGeometryElement::eDirect:
//                        {
//                        //readColor()
//                        break;
//                        }
//                    case FbxGeometryElement::eIndexToDirect:
//                        {
//                            int id = vertex_color->GetIndexArray().GetAt(control_point_index);
//                            //readColor()
//                            break;
//                        }
//
//                    }
//
//                    break;
//
//                case FbxGeometryElement::eByPolygonVertex:
//                    {
//                        switch(vertex_color->GetReferenceMode())
//                        {
//                        case FbxGeometryElement::eDirect:
//                            //readColor
//                            break;
//
//                        case FbxGeometryElement::eIndexToDirect:
//                            int id = vertex_color->GetIndexArray().GetAt(control_point_index);
//                            break;
//                        }
//
//                    }
//                    break;
//
//                case FbxGeometryElement::eByPolygon:
//                case FbxGeometryElement::eAllSame:
//                case FbxGeometryElement::eNone:
//                    break;
//                }
//            } // k loop
//
//            for(int m = 0; m < mesh->GetElementUVCount(); ++m)
//            {
//                FbxGeometryElementUV* uv = mesh->GetElementUV(m);
//
//                switch(uv->GetMappingMode())
//                {
//                case FbxGeometryElement::eByControlPoint:
//                    switch(uv->GetReferenceMode())
//                    {
//                    case FbxGeometryElement::eDirect:
//                        //display2DVector()
//                        break;
//
//                    case FbxGeometryElement::eIndexToDirect:
//                        int id = uv->GetIndexArray().GetAt(control_point_index);
//                        //display2DVector()
//                        break;
//                    }
//                    break;
//
//                case FbxGeometryElement::eByPolygonVertex:
//                    {
//                        int texture_uv_index = mesh->GetTextureUVIndex(i, k);
//
//                        switch(uv->GetReferenceMode())
//                        {
//                        case FbxGeometryElement::eDirect:
//                        case FbxGeometryElement::eIndexToDirect:
//                            {
//                                //display2DVector()
//                                break;
//                            }
//                        }
//                    }
//                    break;
//
//                case FbxGeometryElement::eByPolygon:
//                case FbxGeometryElement::eAllSame:
//                case FbxGeometryElement::eNone:
//                    break;
//                }
//            }	// m loop
//
//            for(int n=0; n < mesh->GetElementNormalCount(); ++n)
//            {
//                FbxGeometryElementNormal* normal = mesh->GetElementNormal(n);
//
//                if(normal->GetMappingMode() == FbxGeometryElement::eByPolygonVertex)
//                {
//                    switch(normal->GetReferenceMode())
//                    {
//                    case FbxGeometryElement::eDirect:
//                        {
//                            //display3DVector()
//                            break;
//                        }
//
//                    case FbxGeometryElement::eIndexToDirect:
//                        {
//                            int id = normal->GetIndexArray().GetAt(vertex_id);
//                            //display3DVector();
//                            break;
//                        }
//                    }
//                }
//            }  // n loop
//
//            for(int m = 0; m < mesh->GetElementTangentCount(); ++m)
//            {
//                FbxGeometryElementTangent* tangent = mesh->GetElementTangent(m);
//
//                if(tangent->GetMappingMode() == FbxGeometryElement::eByPolygonVertex)
//                {
//                    switch(tangent->GetReferenceMode())
//                    {
//                    case FbxGeometryElement::eDirect:
//                        //display3DVector()
//                        break;
//                    
//                    case FbxGeometryElement::eIndexToDirect:
//                        {
//                            int id = tangent->GetIndexArray().GetAt(vertex_id);
//                            //display3DVector()
//                            break;
//                        }
//                    }
//                }
//            }  // m loop
//
//            for(int o = 0; o < mesh->GetElementBinormalCount(); ++o)
//            {
//                FbxGeometryElementBinormal* binormal = mesh->GetElementBinormal(o);
//
//                if(binormal->GetMappingMode() == FbxGeometryElement::eByPolygonVertex)
//                {
//                    switch(binormal->GetReferenceMode())
//                    {
//                    case FbxGeometryElement::eDirect:
//                        //display3DVector;
//                        break;
//
//                    case FbxGeometryElement::eIndexToDirect:
//                        {
//                            int id = binormal->GetIndexArray().GetAt(vertex_id);
//                            //display3DVector
//                            break;
//                        }
//                    }
//                }
//            }  //  o loop
//            vertex_id++;
//        }	// k loop
//        //tmp_mesh.fdata_.push_back(&mesh_triangle);
//    }	// i loop
//
//    for(int p = 0; p < mesh->GetElementVisibilityCount(); ++p)
//    {
//        FbxGeometryElementVisibility* visibility = mesh->GetElementVisibility(p);
//
//        switch(visibility->GetMappingMode())
//        {
//        case FbxGeometryElement::eByEdge:
//            {
//
//                for(int i = 0; i != mesh->GetMeshEdgeCount(); ++i)
//                {
//                    //displayInt();
//                    //displayBool();
//                }
//                break;
//            }
//        }
//    }
//
//
////   DISPLAY MATERIAL MAPPING
//
//    char* mapping_types[] = { "None", "By Control Points", "By Polygon Vertex", "By Polygon", "By Edge", "All Same" };
//    char* reference_mode[] = { "Direct", "Index", "IndexToDirect" };
//
//    int tmp_material_count = 0;
//    
//    FbxNode* node = NULL;
//
//    if(mesh)
//    {
//        node = mesh->GetNode();
//
//        if(node)
//            tmp_material_count = node->GetMaterialCount();
//    }
//
//    for(int i = 0; i < mesh->GetElementMaterialCount(); ++i)
//    {
//        FbxGeometryElementMaterial* material = mesh->GetElementMaterial(i);
//
//        if(material)
//        {
//            int material_count = 0;
//
//            if(material->GetReferenceMode() == FbxGeometryElement::eDirect || 
//                material->GetReferenceMode() == FbxGeometryElement::eIndexToDirect)
//            {
//                material_count = tmp_material_count;
//            }
//
//            if(material->GetReferenceMode() == FbxGeometryElement::eIndex ||
//                material->GetReferenceMode() == FbxGeometryElement::eIndexToDirect)
//            {
//                int i = 0;
//
//                int index_array_count = material->GetIndexArray().GetCount();
//
//                for(i = 0; i < index_array_count; ++i)
//                {
//
//                }
//            }
//        }
//    }
//
////   DISPLAY MATERIAL
//
//    int material_count = 0;
//    //FbxNode* node = NULL;
//    //FbxGeometry* geometry = NULL;
//    if(mesh)
//    {
//        node = mesh->GetNode();
//        if(node)
//        {
//            material_count = node->GetMaterialCount();
//        }
//    }
//
//    if(material_count > 0)
//    {
//        FbxPropertyT<FbxDouble3> fbxDouble3;
//        FbxPropertyT<FbxDouble> fbxDouble1;
//        FbxColor the_color;
//
//        for(int i = 0; i < material_count; ++i)
//        {
//            FbxSurfaceMaterial* material = node->GetMaterial(i);
//            const FbxImplementation* implementation = GetImplementation(material, FBXSDK_IMPLEMENTATION_HLSL);
//            FbxString implementation_type = "HLSL";
//
//            if(!implementation)
//            {
//                implementation = GetImplementation(material, FBXSDK_IMPLEMENTATION_CGFX);
//                implementation_type = "CGFX";
//            }
//
//            if(implementation)
//            {
//                FbxBindingTable const* root_table = implementation->GetRootTable();
//                FbxString filename = root_table->DescAbsoluteURL.Get();
//                FbxString technique_name = root_table->DescTAG.Get();
//
//                FbxBindingTable const* table = implementation->GetRootTable();
//                enginecore::ui entry_num = table->GetEntryCount();
//
//                for(enginecore::ui j = 0; j < entry_num; ++j)
//                {
//                    const FbxBindingTableEntry& entry = table->GetEntry(j);
//                    const char* entry_src_type = entry.GetEntryType(true);
//                    FbxProperty fbx_property;
//
//                    FbxString test = entry.GetSource();
//
//                    if(strcmp(FbxPropertyEntryView::sEntryType, entry_src_type) == 0)
//                    {
//                        fbx_property = material->FindPropertyHierarchical(entry.GetSource());
//
//                        if(!fbx_property.IsValid())
//                        {
//                            fbx_property = material->RootProperty.FindHierarchical(entry.GetSource());
//                        }
//                    }
//                    else if(strcmp(FbxConstantEntryView::sEntryType, entry_src_type) == 0)
//                    {
//                        fbx_property = implementation->GetConstants().FindHierarchical(entry.GetSource());
//                    }
//                    if(fbx_property.IsValid())
//                    {
//                        if(fbx_property.GetSrcObjectCount<FbxTexture>() > 0)
//                        {
//                            for(int k=0; k < fbx_property.GetSrcObjectCount<FbxFileTexture>(); ++k)
//                            {
//                                FbxFileTexture* texture = fbx_property.GetSrcObject<FbxFileTexture>(k);
//                            }
//
//                            for(int k=0; k < fbx_property.GetSrcObjectCount<FbxLayeredTexture>(); ++k)
//                            {
//                                FbxLayeredTexture* texture = fbx_property.GetSrcObject<FbxLayeredTexture>(k);
//                            }
//
//                            for(int k=0; k < fbx_property.GetSrcObjectCount<FbxProceduralTexture>(); ++k)
//                            {
//                                FbxProceduralTexture* texture = fbx_property.GetSrcObject<FbxProceduralTexture>(k);
//                            }
//                        }
//                        else
//                        {
//                            FbxDataType fbx_type = fbx_property.GetPropertyDataType();
//                            FbxString temp = fbx_type.GetName();
//                            if(FbxBoolDT == fbx_type)
//                            {
//                                //displayBool()
//                            }
//                            else if(FbxIntDT == fbx_type || FbxEnumDT == fbx_type)
//                            {
//                                //displayInt()
//                            }
//                            else if(FbxFloatDT == fbx_type)
//                            {
//                                //displayDouble()
//                            }
//                            else if(FbxDoubleDT == fbx_type)
//                            {
//                                //displayDouble()
//                            }
//                            else if(FbxStringDT == fbx_type || FbxUrlDT == fbx_type || FbxXRefUrlDT == fbx_type)
//                            {
//                                //displayString()
//                            }
//                            else if(FbxDouble2DT == fbx_type)
//                            {
//                                FbxDouble2 double2 = fbx_property.Get<FbxDouble2>();
//                                FbxVector2 vector;
//                                vector[0] = double2[0];
//                                vector[1] = double2[1];
//
//                                //displayVector()
//                            }
//                            else if(FbxDouble3DT == fbx_type || FbxColor3DT == fbx_type)
//                            {
//                                FbxDouble3 double3 = fbx_property.Get<FbxDouble3>();
//
//                                FbxVector4 vector;
//                                vector[0] = double3[0];
//                                vector[1] = double3[1];
//                                vector[2] = double3[2];
//                            }
//                            else if(FbxDouble4DT == fbx_type || FbxColor3DT == fbx_type)
//                            {
//                                FbxDouble4 double4 = fbx_property.Get<FbxDouble4>();
//
//                                FbxVector4 vector;
//                                vector[0] = double4[0];
//                                vector[1] = double4[1];
//                                vector[2] = double4[2];
//                                vector[3] = double4[3];
//                            }
//                            else if(FbxDouble4x4DT == fbx_type)
//                            {
//                                FbxDouble4x4 double4x4 = fbx_property.Get<FbxDouble4x4>();
//
//                                for(int i =0; i < 4; ++i)
//                                {
//                                    FbxVector4 vector;
//
//                                    vector[0] = double4x4[i][0];
//                                    vector[1] = double4x4[i][1];
//                                    vector[2] = double4x4[i][2];
//                                    vector[3] = double4x4[i][3];
//                                }
//                            }
//                        }
//                    }
//                }  // j loop
//            }
//            else if(material->GetClassId().Is(FbxSurfacePhong::ClassId))
//            {
//                fbxDouble3 = ((FbxSurfacePhong*)material)->Ambient;
//                the_color.Set(fbxDouble3.Get()[0], fbxDouble3.Get()[1], fbxDouble3.Get()[2]);
//
//                fbxDouble3 = ((FbxSurfacePhong*)material)->Diffuse;
//                the_color.Set(fbxDouble3.Get()[0], fbxDouble3.Get()[1], fbxDouble3.Get()[2]);
//
//                fbxDouble3 = ((FbxSurfacePhong*)material)->Specular;
//                the_color.Set(fbxDouble3.Get()[0], fbxDouble3.Get()[1], fbxDouble3.Get()[2]);
//
//                fbxDouble3 = ((FbxSurfacePhong*)material)->Emissive;
//                the_color.Set(fbxDouble3.Get()[0], fbxDouble3.Get()[1], fbxDouble3.Get()[2]);
//
//                fbxDouble1 = ((FbxSurfacePhong*)material)->TransparencyFactor;
//
//                fbxDouble1 = ((FbxSurfacePhong*)material)->Shininess;
//
//                fbxDouble1 = ((FbxSurfacePhong*)material)->ReflectionFactor;
//            }
//            else if(material->GetClassId().Is(FbxSurfaceLambert::ClassId))
//            {
//                fbxDouble3 = ((FbxSurfaceLambert*)material)->Ambient;
//                the_color.Set(fbxDouble3.Get()[0], fbxDouble3.Get()[1], fbxDouble3.Get()[2]);
//
//                fbxDouble3 = ((FbxSurfaceLambert*)material)->Diffuse;
//                the_color.Set(fbxDouble3.Get()[0], fbxDouble3.Get()[1], fbxDouble3.Get()[2]);
//
//                fbxDouble3 = ((FbxSurfaceLambert*)material)->Emissive;
//                the_color.Set(fbxDouble3.Get()[0], fbxDouble3.Get()[1], fbxDouble3.Get()[2]);
//
//                fbxDouble1 = ((FbxSurfaceLambert*)material)->TransparencyFactor;
//            }
//            else
//            {
//                FbxPropertyT<FbxString> string;
//                string = material->ShadingModel;
//            }
//
//        }
//    }
//    
//
//    //  DISPLAY TEXTURE
//
//    int material_index = 0;
//
//    FbxProperty fbx_property;
//
//    if(mesh->GetNode() == NULL)
//    {
//        return;
//    }
//
//    int number_material = mesh->GetNode()->GetSrcObjectCount<FbxSurfaceMaterial>();
//
//    for(material_index = 0; material_index < number_material; ++material_index)
//    {
//        FbxSurfaceMaterial* material = mesh->GetNode()->GetSrcObject<FbxSurfaceMaterial>(material_index);
//        bool display_header = true;
//
//        if(material)
//        {
//            int texture_index = 0;
//            FBXSDK_FOR_EACH_TEXTURE(texture_index)
//            {
//                fbx_property = material->FindProperty(FbxLayerElement::sTextureChannelNames[texture_index]);
//
//                if(fbx_property.IsValid())
//                {
//                    int texture_count = fbx_property.GetSrcObjectCount<FbxTexture>();
//
//                    for(int i = 0; i < texture_count; ++i)
//                    {
//                        FbxLayeredTexture* layered_texture = fbx_property.GetSrcObject<FbxLayeredTexture>(i);
//
//                        if(layered_texture)
//                        {
//                            FbxLayeredTexture* layered_texture = fbx_property.GetSrcObject<FbxLayeredTexture>(i);
//                            int number_of_textures = layered_texture->GetSrcObjectCount<FbxTexture>();
//
//                            for(int j=0; j < number_of_textures; ++j)
//                            {
//                                FbxTexture* texture = layered_texture->GetSrcObject<FbxTexture>(j);
//
//                                if(texture)
//                                {
//                                    if(display_header)
//                                    {
//                                        display_header = false;
//                                    }
//
//                                    FbxLayeredTexture::EBlendMode blend_mode;
//                                    layered_texture->GetTextureBlendMode(j, blend_mode);
//                                }
//                            }	//  j loop
//                        }
//                        else
//                        {
//                            FbxTexture* texture = fbx_property.GetSrcObject<FbxTexture>(i);
//
//                            if(texture)
//                            {
//                                if(display_header)
//                                {
//                                    display_header = false;
//                                }
//                            }
//                        }
//
//                    }	//i loop
//                }
//            }
//        }
//    }	//  material_index loop
//
//    
//    //   DISPLAY MATERIAL CONNECTIONS
//
//    int i = 0;
//    int l = 0;
//    int polygon_count_material = 0;
//
//    bool is_all_same = true;
//
//    for(l = 0; l < mesh->GetElementMaterialCount(); ++l)
//    {
//        FbxGeometryElementMaterial* material_element = mesh->GetElementMaterial(l);
//
//        if(material_element->GetMappingMode() == FbxGeometryElement::eByPolygon)
//        {
//            is_all_same = false;
//            break;
//        }
//    }
//
//    if(is_all_same)
//    {
//        for(l = 0; l < mesh->GetElementMaterialCount(); ++l)
//        {
//            FbxGeometryElementMaterial* material_element = mesh->GetElementMaterial(l);
//
//            if(material_element->GetMappingMode() == FbxGeometryElement::eAllSame)
//            {
//                FbxSurfaceMaterial* material = mesh->GetNode()->GetMaterial(material_element->GetIndexArray().GetAt(0));
//
//                int material_id = material_element->GetIndexArray().GetAt(0);
//
//                if(material_id >= 0)
//                {
//
//                }
//            }
//        }
//    }
//    else
//    {
//        for(i = 0; i < polygon_count_material; ++i)
//        {
//            for(l = 0; l < mesh->GetElementMaterialCount(); ++l)
//            {
//                FbxGeometryElementMaterial* material_element = mesh->GetElementMaterial(l);
//                FbxSurfaceMaterial* material = NULL;
//                int material_id = -1;
//
//                material = mesh->GetNode()->GetMaterial(material_element->GetIndexArray().GetAt(i));
//                material_id = material_element->GetIndexArray().GetAt(i);
//
//                if(material_id >= 0)
//                {
//
//                }
//            }
//        }
//    }
//
//    //   DISPLAY LINK
//        
//    int skin_count = 0;
//    int cluster_count = 0;
//    FbxCluster* cluster;
//
//    skin_count = mesh->GetDeformerCount(FbxDeformer::eSkin);
//
//    for(int i=0; i != skin_count; ++i)
//    {
//        cluster_count = ((FbxSkin*)mesh->GetDeformer(i, FbxDeformer::eSkin))->GetClusterCount();
//
//        for(int j=0; j != cluster_count; ++j)
//        {
//            cluster = ((FbxSkin*)mesh->GetDeformer(i, FbxDeformer::eSkin))->GetCluster(j);
//
//            char* cluster_modes[] = { "Normalize", "Additive", "Total1" };
//
//            int index_count = cluster->GetControlPointIndicesCount();
//            int* indices = cluster->GetControlPointIndices();
//            double* weights = cluster->GetControlPointWeights();
//
//            for(int k=0; k < index_count; ++k)
//            {
//
//            }
//
//            FbxAMatrix matrix; 
//
//            matrix = cluster->GetTransformMatrix(matrix);
//            matrix = cluster->GetTransformLinkMatrix(matrix);
//        }
//    }
//
//    //   DISPLAY SHAPE
//
//    int blend_shape_count = 0;
//    int blend_shape_channel_count = 0; 
//    int target_shape_count = 0;
//
//    FbxBlendShape* blend_shape;
//    FbxBlendShapeChannel* blend_shape_channel;
//    FbxShape* shape;
//
//    blend_shape_count = mesh->GetDeformerCount(FbxDeformer::eBlendShape);
//
//    for(int blend_shape_index = 0; blend_shape_index < blend_shape_count; ++blend_shape_index)
//    {
//        blend_shape = (FbxBlendShape*)mesh->GetDeformer(blend_shape_index, FbxDeformer::eBlendShape);
//
//        blend_shape_channel_count = blend_shape->GetBlendShapeChannelCount();
//
//        for(int blend_shape_channel_index = 0; blend_shape_channel_index < blend_shape_channel_count; ++blend_shape_channel_index)
//        {
//            blend_shape_channel = blend_shape->GetBlendShapeChannel(blend_shape_channel_index);
//            target_shape_count = blend_shape_channel->GetTargetShapeCount();
//
//            for(int target_shape_index = 0; target_shape_index < target_shape_count; ++target_shape_index)
//            {
//                shape = blend_shape_channel->GetTargetShape(target_shape_index);
//
//                int j = 0;
//                int control_points_count = shape->GetControlPointsCount();
//                FbxVector4* control_points = shape->GetControlPoints();
//                FbxLayerElementArrayTemplate<FbxVector4>* normals = NULL;
//
//                bool status = shape->GetNormals(&normals);
//
//                for(int i=0; j < control_points_count; ++i)
//                {
//
//                }
//            }
//        }
//    }
//
//
//    //model_.mesh_count_++;
//    //model_.mesh_.push_back(tmp_mesh);
//
//}
//
////------------------------------
//
//void FileFBX::readFile(FbxScene* scene)
//{
//    FbxNode* node = scene->GetRootNode();
//
//    if(node)
//    {
//        for(int i = 0; i < node->GetChildCount(); ++i)
//        {
//            readContent(node->GetChild(i));
//        }
//    }
//}
//
////------------------------------
//
//void FileFBX::readContent(FbxNode* node)
//{
//    FbxNodeAttribute::EType attributeType;
//
//    if(node->GetNodeAttribute() == NULL)
//    {
//        MessageBox(NULL, "NULL Node Attribute", enginecore::HEADER, enginecore::errIconOK);
//    }
//    else
//    {
//        attributeType = (node->GetNodeAttribute()->GetAttributeType());
//
//        switch(attributeType)
//        {
//        case FbxNodeAttribute::eMarker:
//
//            readMarker(node);
//
//            break;
//
//        case FbxNodeAttribute::eSkeleton:
//
//            readSkeleton(node);
//            
//            break;
//
//        case FbxNodeAttribute::eMesh:
//
//            readMesh(node);
//
//            break;
//
//        case FbxNodeAttribute::eNurbs:
//
//            readNurbs(node);
//
//            break;
//
//        case FbxNodeAttribute::ePatch:
//
//            readPatch(node);
//
//            break;
//
//        case FbxNodeAttribute::eCamera:
//
//            readCamera(node);
//
//            break;
//
//        case FbxNodeAttribute::eLight:
//
//            readLight(node);
//
//            break;
//
//        case FbxNodeAttribute::eLODGroup:
//
//            readLODGroup(node);
//
//            break;
//
//        }
//    }
//
//    for(int i=0; i < node->GetChildCount(); ++i)
//    {
//        readContent(node->GetChild(i));
//    }
//}
//
////---------------------------------------
//
//void FileFBX::readstring(const char* header, const char* value, const char* suffix)
//{
//    std::string tmp;
//    tmp = header;
//    tmp += value;
//    tmp += suffix;
//}
//
////---------------------------------------
//
//void FileFBX::readMarker(FbxNode* node)
//{
//    FbxMarker* marker = dynamic_cast<FbxMarker*>(node->GetNodeAttribute());
//    FbxString string;
//
//    switch(marker->GetType())
//    {
//    case FbxMarker::eStandard: string += "Standard"; break;
//    case FbxMarker::eOptical: string += "Optical"; break;
//    case FbxMarker::eEffectorIK: string += "EffectorIK"; break;
//    case FbxMarker::eEffectorFK: string += "EffectorFK"; break;
//    }
//
//    switch(marker->Look.Get())
//    {
//    case FbxMarker::eCube: string += "Cube"; break;
//    case FbxMarker::eHardCross: string += "Hard Cross"; break;
//    case FbxMarker::eLightCross: string += "Light Cross"; break;
//    case FbxMarker::eSphere: string += "Sphere"; break;
//    }
//
//    FbxDouble3 temp_color = marker->Color.Get();
//    FbxColor color(temp_color[0], temp_color[1], temp_color[2]); 
//}
//
////----------------------------------------
//
//void FileFBX::readSkeleton(FbxNode* node)
//{
//    FbxSkeleton* skeleton = dynamic_cast<FbxSkeleton*>(node->GetNodeAttribute());
//
//    char* skeleton_types[] = { "Root", "Limb", "Limb Node", "Effector" };
//}
//
////----------------------------------------
//
//void FileFBX::readNurbs(FbxNode* node)
//{
//    FbxNurbs* nurbs = dynamic_cast<FbxNurbs*>(node->GetNodeAttribute());
//
//    char* surface_modes[] = { "Raw", "Low No Normals", "Low", "High No Normals", "High" };
//
//    int control_points_count = nurbs->GetControlPointsCount();
//    FbxVector4* control_points = nurbs->GetControlPoints();
//
//    char* nurb_types[] = { "Periodic", "Closed", "Open" };
//}
//
//
////-----------------------------------------------------
//
//void FileFBX::readPatch(FbxNode* node)
//{
//    FbxPatch* patch = dynamic_cast<FbxPatch*>(node->GetNodeAttribute());
//
//    char* surface_modes[] = { "Raw", "Low No Normals", "Low", "High No Normals", "High" };
//
//    int control_points_count = patch->GetControlPointsCount();
//    FbxVector4* control_points = patch->GetControlPoints();
//
//    char* patch_types[] = { "Bezier", "Bezier Quadric", "Cardinal", "B-Spline", "Linear" };
//}
//
//
////----------------------------------------------------
//
//void FileFBX::readCamera(FbxNode* node)
//{
//
//}
//
////-----------------------------------------------------
//
//void FileFBX::readLight(FbxNode* node)
//{
//
//}
//
////-----------------------------------------------------
//
//void FileFBX::readLODGroup(FbxNode* node)
//{
//
//}
//
//
////END OF NAMESPACE
//}